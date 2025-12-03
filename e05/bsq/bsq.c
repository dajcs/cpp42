/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:17:14 by anemet            #+#    #+#             */
/*   Updated: 2025/12/03 09:48:24 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name              : bsq
Expected files               : *.c *.h
Allowed functions and globals: malloc, calloc, realloc, free, fopen, fclose,
getline, fscanf, fputs, fprintf, stderr, stdout, stdin, errno
--------------------------------------------------------------------------------

The aim of this program is to find the biggest square on a map, avoiding obstacles.
A file containing the map will be provided. It'll have to be passed as an argument for your program.
The first line of the map contains information on how to read the map (space separated) :
 - The number of lines on the map;
 - The "empty" character;
 - The "obstacle" character;
 - The "full" character.
The map is made up of '"empty" characters', lines and '"obstacle" characters'.
The aim of the program is to replace '"empty" characters' by '"full" characters' in order to represent the biggest square possible.
In the case that more than one solution exists, we'll choose to represent the square that's closest to the top of the map, then the one that's most to the left.
When your program receives more than one map in argument, each solution or "map error" must be followed by a line break.
Should there be no passed arguments, your program must be able to read on the standard input.

cat example.txt | ./a.out

Definition of a valid map :
 - All lines must have the same length.
 - There's at least one line of at least one box.
 - At each end of line, there's a line break.
 - The characters on the map can only be those introduced in the first line.
 - The map is invalid if a character is missing from the first line, or if two characters (of empty, full and obstacle) are identical.
 - The characters can be any printable character, even numbers.
 - In case of an invalid map, your program should display "map error" on the error output followed by a line break. Your program will then move on to the next map.

example:
%>cat example_file
9 . o x
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

#include "bsq.h"

/*
	======== Utils ============
*/
// returns length of a string without terminating '\n'
int ft_strlen(char *s)
{
	int len = 0;

	while (s[len] && s[len] != '\n')
		len++;
	return len;
}

int is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

// free map->grid
void free_grid(t_map *map)
{
	int i;

	// free each line of the grid
	for (i = 0; i < map->rows; i++)
	{
		if (map->grid && map->grid[i])
			free(map->grid[i]);
	}
	// free pointers to the lines
	if (map->grid)
	{
		free(map->grid);
		map->grid = NULL;
	}
}


// ============ Read and Validate ==========

// Read from file or STDIN
// Input:
//		- tmap *map : pointer to the map where to store data
//		- char *file: filename to read or NULL for STDIN
// Return:
//		- map ptr if map valid, NULL if there was an error
t_map *read_file(t_map *map, char *file)
{
	FILE	*fp;
	char	*line;
	size_t	len;
	int		i, j, line_len;

	// Open file or use STDIN
	fp = file ? fopen(file, "r") : stdin;
	if (!fp)
		return NULL;

	/* Read and validate first line (map parameters) */
	// %d -> skip leading white spaces, read number
	// space ' ' -> skip any white-space, %c -> read exactly 1 character
	// terminating ' \n' -> skip all remaing white space till end of line (consume line)
	if (fscanf(fp, "%d %c %c %c \n",
				&map->rows, &map->empty, &map->obs, &map->full) != 4)
	{
		if (file) fclose(fp);
		return NULL;
	}

	// validate parameters
	if (map->rows <= 0 ||
		map->empty == map->obs || map->obs == map->full || map->full == map->empty ||
		!is_printable(map->empty) || !is_printable(map->obs) || !is_printable(map->full) )
	{
		if (file) fclose(fp);
		return NULL;
	}

	// --- Initialize grid ---
	map->cols = 0;
	map->grid = calloc(map->rows, sizeof(char *));
	if (!map->grid)
	{
		if (file) fclose(fp);
		return NULL;
	}

	// --- Read and validate each line of the map ---
	for (i = 0; i < map->rows; i++)
	{
		line = NULL;
		len = 0;

		// read the line
		if (getline(&line, &len, fp) == -1)
		{
			if (file) fclose(fp);
			return NULL;
		}
		// process line length
		line_len = ft_strlen(line);
		if (line[line_len] == '\n')
				line[line_len] = '\0';
		// validate consistent line length
		if (i == 0)
		{
			map->cols = line_len;
		}
		else if (line_len != map->cols)
		{
			free(line);
			if (file) fclose(fp);
			return NULL;
		}
		// validate allowed chars
		for (j = 0; j < map->cols; j++)
		{
			if (line[j] != map->empty && line[j] != map->obs)
			{
				free(line);
				if (file) fclose(fp);
				return NULL;
			}
		}
		map->grid[i] = line;
	}

	// --- verify that there are no extra lines ---
	line = NULL;
	len = 0;
	if (getline(&line, &len, fp) != -1)
	{
		free(line);
		if (file) fclose(fp);
		return NULL;
	}
	free(line);

	if (file) fclose(fp);
	return map;
}

// ======== Solving BSQ =============

/*
	check_size_exp()
	Try to expand the square size by one
	Checks if a square of size 'curr_size + 1' is valid at (x0, y0)
		- checks the new bottom-right corner
		- checks the new bottom row segment
		- checks the new right column segment
	Return: 1 if expansion ok, 0 otherwise
*/
int check_size_exp(t_map *map, int r, int c, int curr_size)
{
	int i;

	// 0. check boundaries of the new square
	if (r + curr_size >= map->rows || c + curr_size >= map->cols)
		return 0;

	// 1. check for obstacle at the diagonal bottom right corner [x0+size][y0+size]
	if (map->grid[r + curr_size][c + curr_size] == map->obs)
		return 0;

	// 2. check the new row (y0+size) on [x0, x0+size)
	for (i = 0; i < curr_size; i++)
	{
		if (map->grid[r + curr_size][c + i] == map->obs)
			return 0;
	}

	// 3. check the new right column (x0+size) on [y0, y0+size)
	for (i = 0; i < curr_size; i++)
	{
		if (map->grid[r + i][c + curr_size] == map->obs)
			return 0;
	}

	return 1;
}



/*
	solve_bsq()
	A simple solution, no optimization, but easy to understand
	1.) Iterate every cell (r, c)
	2.) If empty, try to expand size from 1
	3.) Check the limits of expansion
	4.) Update the global max if new size if bigger
*/
void solve_bsq(t_map *map)
{
	int r, c;		// row and column iterator
	int curr_size;	// square size iterator

	map->size = 0; // init global best size

	// 1. Go to each cell of the map
	for (r = 0; r < map->rows; r++)
	{
		for (c = 0; c < map->cols; c++)
		{
			// 2. If cell is empty
			if (map->grid[r][c] == map->empty)
			{
				curr_size = 1;  // current square size

				// Loop increasing curr_size to check expansion validity
				while (1)
				{
					if (check_size_exp(map, r, c, curr_size))
						// if expansion ok increment size
						curr_size++;
					else
						// obstacle or boundary reached
						break;
				}
				// Update global maximum
				// Using > (strictly greater)
				// 		this ensures we keep the solution "closest to top, then left"
				if (curr_size > map->size)
				{
					map->size = curr_size;
					map->y0 = r;
					map->x0 = c;
				}
			}
		}
	}
}


// ============= Input / Output ============

void print_map(t_map *map)
{
	int i, j;

	// if valid square was found (size > 0) fill the square
	if (map->size > 0)
	{
		for (i = 0; i < map->size; i++)
		{
			for (j = 0; j < map->size; j++)
			{
				map->grid[map->y0 + i][map->x0 + j] = map->full;
			}
		}
	}

	// print the map
	for (i = 0; i < map->rows; i++)
		fprintf(stdout, "%s\n", map->grid[i]);
}


void process_input(t_map *map, char *file)
{
	// try to read and validate the map
	if (read_file(map, file) != NULL)
	{
		// if valid solve and print
		solve_bsq(map);
		print_map(map);
	}
	else
	{
		fprintf(stderr, "map error\n");
	}
	// free map->grid
	free_grid(map);
}







// ============ Main ===============
int main(int argc, char **argv)
{
	t_map *map;
	int i;

	// assign memory for map struct
	map = calloc(1, sizeof(t_map));
	if (!map)
		return 1;

	// --- no arguments -> read STDIN ---
	if (argc < 2)
	{
		process_input(map, NULL);
	}
	// --- if arguments -> process each file ---
	else
	{
		for (i = 1; i < argc; i++)
		{
			process_input(map, argv[i]);
			fprintf(stdout, "\n");
		}
	}
	// free map
	free(map);
	return 0;
}
