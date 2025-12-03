/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:39:13 by anemet            #+#    #+#             */
/*   Updated: 2025/12/03 12:21:42 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name              : bsq
Expected files               : *.c *.h
Allowed functions and globals: malloc, calloc, realloc, free, fopen, fclose,
getline, fscanf, fputs, fprintf, stderr, stdout, stdin, printf
--------------------------------------------------------------------------------

The aim of this program is to find the biggest square on a map, avoiding obstacles.
A file containing the map will be provided. It'll have to be passed as an argument for your program.
The first line of the map contains information on how to read the map:
 - The number of lines on the map;
 - The "empty" character;
 - The "obstacle" character;
 - The "full" character.
The map is made up of '"empty" characters', lines and '"obstacle" characters'.
The aim of the program is to replace '"empty" characters' by '"full" characters' in order to represent the biggest square possible.
In the case that more than one solution exists, we'll choose to represent the square that's closest to the top of the map, then the one that's most to the left.
In case of map error "Error: invalid map\n" should be printed, other errors should be "Error: <reason>\n"
The program receives 1 argument - the map filename,
but it must read the map from the standard input when there there is no argument.

cat example.txt | ./a.out

Definition of a valid map :
 - All lines must have the same length.
 - There's at least one line of at least one box.
 - At each end of line, there's a line break.
 - The characters on the map can only be those introduced in the first line.
 - The map is invalid if a character is missing from the first line, or if two characters (of empty, full and obstacle) are identical.
 - The characters can be any printable characters, even numbers.
 - In case of an invalid map, your program should display "map error" on the error output followed by a line break. Your program will then move on to the next map.

example:
%>cat example_file
9.ox
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................
%>./bsq example_file
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxxo..............
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxx...o...........
.....xxxxxxx...............
......o..............o.....
..o.......o................
%>
*/

/*

Solution with DP: single pass over map -> O(N^2)

- Create a grid of ints the same size as the map
- in the ints put the value:
	what is the biggest square size X that has bottom right corner here?
		- on the first row or first column if grid is empty then 1, for obstacle 0
		- on the other rows: min(left, top, top-left) + 1
			where:
				left -> value[i][j-1]
				top -> value[i-1][j]
				top-left -> value[i-1][j-1]


*/

#include <stdlib.h>
#include <stdio.h>

typedef struct s_map
{
	int rows;
	int cols;
	char empty;
	char obs;
	char full;
	char** grid;
	int r0;  // bsq upper left corner row
	int c0;  // bsq upper left corner column
	int size; // bsq size
}	t_map;

int is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int ft_strlen(char* str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

// return min of 3 int
int min_val(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;
	return c;
}

void free_grid(t_map *map)
{
	if (map->grid)
	{
		for (int i = 0; i < map->rows; i++)
		{
			if (map->grid[i])
			{
				free(map->grid[i]);
			}
		}
		free(map->grid);
		map->grid = NULL; // reset pointer after free
	}
}

int errx(char* fname, FILE* stream, char* line, t_map* map, char* message)
{
	if (fname)
		fclose(stream);
	if (line)
		free(line);
	free_grid(map);
	printf("Error: %s\n", message);
	return 0;
}

// parse str up to <stop>
// skipping the trailing 3 chars + '\n'
int ftx_atoi(char* str, int stop)
{
	int i = 0;
	int res = 0;
	while (i < stop)
	{
		if (is_digit(str[i]))
		{
			int digit = str[i] - '0';
			res = 10 * res + digit;
		}
		else
		{
			// invalid map
			return 0;
		}
		i++;
	}
	return res;
}

// read map from char* fname
// if char* fname == NULL -> STDIO
// return 1 on success, 0 on failure
int read_map(char* fname, t_map* map)
{
	FILE* stream;
	char *line = NULL;
	size_t len = 0;
	int nread;

	if (fname)
	{
		stream = fopen(fname, "r");
		if (!stream)
			return errx(NULL, NULL, NULL, map, "fopen()");
	}
	else
		stream = stdin;

/*
	this would work if characters are space separated, or if `empty` chars wouldn't be allowed to be digits.

	// read first line params
	nread = fscanf(stream, "%d %c %c %c \n", &map->rows, &map->empty, &map->obs, &map->full);
	if (nread < 4)
	{
		return reterror(fname, stream, line, map, "invalid map");
	}
*/

	// parse first line
	nread = getline(&line, &len, stream);
	if (nread < 5) // we need at least 4 chars + '\n'
	{
		return errx(fname, stream, line, map, "invalid map");
	}
	int length = ft_strlen(line);  // example line: 9.ox\n
	// line[length - 1] -> '\n'
	map->full = line[length - 2]; // x
	map->obs = line[length - 3]; // o
	map->empty = line[length - 4]; // .
	map->rows = ftx_atoi(line, length - 4);
	// printf("map->rows: %d\n", map->rows);

	if (map->rows <= 0 ||
		map->empty == map->obs || map->obs == map->full || map->full == map->empty ||
		!is_printable(map->empty) || !is_printable(map->obs) || !is_printable(map->full))
	{
		return errx(fname, stream, line, map, "invalid map");
	}

	// read map lines
	for (int r = 0; r < map->rows; r++)
	{
		line = NULL;  // getline will provide a buffer, but we have to free it
		len = 0;

		nread = getline(&line, &len, stream);
		if (nread <= 1)  // we need at least one 'empty'/'obs' + '\n'
		{
			return errx(fname, stream, line, map, "invalid map");
		}
		if (r == 0) // first rows
		{
			map->cols = nread - 1; // without terminating '\n'
			map->grid = (char **)calloc(map->rows, sizeof(char *));
			if (!map->grid)
				return errx(fname, stream, line, map, "invalid map");
		}
		else if (nread - 1 != map->cols)  // rows must have the same size
		{
			return errx(fname, stream, line, map, "invalid map");
		}

		// store line
		map->grid[r] = calloc(map->cols + 1, sizeof(char));  // +1 for terminating '\0' (easy print)
		if (!map->grid[r])
		{
			return errx(fname, stream, line, map, "invalid map");
		}
		for (int c = 0; c < map->cols; c++)
		{
			map->grid[r][c] = line[c];
			if (line[c] != map->empty && line[c] != map->obs)
			{
				return errx(fname, stream, line, map, "invalid map");
			}
		}
		free(line);
		line = NULL;  // reset pointer after free
	}

	// check EOF after all lines consumed
	nread = getline(&line, &len, stream);
	if (nread == -1) // EOF
	{
		fclose(stream);
		free(line);
	}
	else
	{
		return errx(fname, stream, line, map, "invalid map");
	}

	return 1;


}


void print_map(t_map* map)
{
	// fill map
	for (int i = 0; i < map->size; i++)
	{
		for (int j = 0; j < map->size; j++)
		{
			map->grid[map->r0 + i][map->c0 + j] = map->full;
		}
	}

	for (int r = 0; r < map->rows; r++)
	{
		fprintf(stdout, "%s\n", map->grid[r]);
	}
	// printf("\nr0: %d, c0: %d, size: %d\n\n", map->r0, map->c0, map->size);
}
/*
int expand_size(int r, int c, int size, t_map* map)
{
	// check boudaries
	if (r + size >= map->rows || c + size >= map->cols)
		return 0;
	// check lower right corner
	if (map->grid[r + size][c + size] == map->obs)
		return 0;
	for (int i = 0; i < size; i++)
	{
		// check cells in the new row
		if (map->grid[r + size][c + i] == map->obs)
			return 0;
		// check cells in the new column
		if (map->grid[r + i][c + size] == map->obs)
			return 0;
	}
	return 1;
}

void solve_map(t_map* map)
{
	int size = 0;

	for (int r = 0; r < map->rows; r++)
	{
		for (int c = 0; c < map->cols; c++)
		{
			if (map->grid[r][c] == map->empty)
			{
				size = 1;
				while (expand_size(r, c, size, map))
				{
					size++;
				}
				if (size > map->size)
				{
					map->r0 = r;
					map->c0 = c;
					map->size = size;
				}
			}
		}
	}
	return;
}
*/

void solve_dp(t_map *map)
{

	// 1. Allocate mem for the int grid
	int **dp = (int**)calloc(map->rows, sizeof(int *));
	if (!dp)
		errx(NULL, NULL, NULL, map, "(int**)calloc fail");
	for (int i = 0; i < map->rows; i++)
	{
		dp[i] = (int*)calloc(map->cols, sizeof(int));
	}

	map->size = 0; // bsq size

	// 2. Iterate through the map
	for (int r = 0; r < map->rows; r++)
	{
		for (int c = 0; c < map->cols; c++)
		{
			// if obs -> val = 0
			if (map->grid[r][c] == map->obs)
				dp[r][c] = 0;

			// if first row or first col when empty val = 1
			else if (r == 0 || c == 0)
				dp[r][c] = 1;

			// else calculate based on neighbours
			else
				dp[r][c] = min_val(dp[r][c-1], dp[r-1][c], dp[r-1][c-1]) + 1;

			// 3. check if we have a new bsq
			if (dp[r][c] > map->size)
			{
				map->size = dp[r][c];
				// put top-left corner in struct
				map->r0 = r - map->size + 1;
				map->c0 = c - map->size + 1;
			}

		}
	}

	// free int grid
	for (int i = 0; i < map->rows; i++)
	{
		free(dp[i]);
	}
	free(dp);
}


int main(int argc, char* argv[])
{
	t_map map = {0};
	char* fname = NULL;

	if (argc > 1)
		fname = argv[1];

	read_map(fname, &map);
	solve_dp(&map);
	print_map(&map);
	free_grid(&map);

	return 0;
}
