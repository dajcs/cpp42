/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:39:13 by anemet            #+#    #+#             */
/*   Updated: 2025/12/02 10:02:48 by anemet           ###   ########.fr       */
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

#include <stdlib.h>
#include <stdio.h>

typedef struct s_map
{
	int row;
	int col;
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

void free_map_grid(t_map *map)
{
	if (map->grid)
	{
		for (int i = 0; i < map->row; i++)
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

int map_error(char* fname, FILE* stream, char* line, t_map* map)
{
	if (fname)
		fclose(stream);
	if (line)
		free(line);
	free_map_grid(map);
	fputs("map error\n", stderr);
	return 0;
}

// read map from char* fname
// if char* fname == NULL -> STDIO
// return 1 on success, 0 on failure
int read_map(char* fname, t_map* map)
{
	FILE* stream;
	// t_map* map;
	char *line = NULL;
	size_t len = 0;
	int nread;

	if (fname)
	{
		stream = fopen(fname, "r");
		if (!stream)
			return map_error(NULL, NULL, NULL, map);
	}
	else
		stream = stdin;

	// read first line params
	nread = fscanf(stream, "%d %c %c %c \n", &map->row, &map->empty, &map->obs, &map->full);
	if (nread < 4)
	{
		return map_error(fname, stream, line, map);
	}
	if (map->row <= 0 ||
		map->empty == map->obs || map->obs == map->full || map->full == map->empty ||
		!is_printable(map->empty) || !is_printable(map->obs) || !is_printable(map->full))
	{
		return map_error(fname, stream, line, map);
	}

	// read map lines
	for (int r = 0; r < map->row; r++)
	{
		line = NULL;  // getline will provide a buffer, but we have to free it
		len = 0;

		nread = getline(&line, &len, stream);
		if (nread <= 1)  // we need at least one 'empty'/'obs' + '\n'
		{
			return map_error(fname, stream, line, map);
		}
		if (r == 0) // first row
		{
			map->col = nread - 1; // without terminating '\n'
			map->grid = (char **)calloc(map->row, sizeof(char *));
			if (!map->grid)
				return map_error(fname, stream, line, map);
		}
		else if (nread - 1 != map->col)  // rows must have the same size
		{
			return map_error(fname, stream, line, map);
		}

		// store line
		map->grid[r] = calloc(map->col + 1, sizeof(char));  // +1 for terminating '\0' (easy print)
		if (!map->grid[r])
		{
			return map_error(fname, stream, line, map);
		}
		for (int c = 0; c < map->col; c++)
		{
			map->grid[r][c] = line[c];
			if (line[c] != map->empty && line[c] != map->obs)
			{
				return map_error(fname, stream, line, map);
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
		return map_error(fname, stream, line, map);
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

	for (int r = 0; r < map->row; r++)
	{
		fprintf(stdout, "%s\n", map->grid[r]);
	}

}

int expand_size(int r, int c, int size, t_map* map)
{
	// check boudaries
	if (r + size >= map->row || c + size >= map->col)
		return 0;
	// check lower right corner
	if (map->grid[r + size][c + size] == map->obs)
		return 0;
	for (int i = 0; i < size; i++)
	{
		// check new row
		if (map->grid[r + size][c + i] == map->obs)
			return 0;
		// check new column
		if (map->grid[r + i][c + size] == map->obs)
			return 0;
	}
	return 1;
}

void solve_map(t_map* map)
{
	int size = 0;

	for (int r = 0; r < map->row; r++)
	{
		for (int c = 0; c < map->col; c++)
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

void process_map(t_map* map)
{
	solve_map(map);
	print_map(map);
	free_map_grid(map);
}



int main(int argc, char* argv[])
{
	t_map map = {0};

	if (argc == 1)
	{
		if (read_map(NULL, &map))
			process_map(&map);
		else
			return 1;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			map = (t_map){0}; // reset before each file
			if (read_map(argv[i], &map))
				process_map(&map);
			fputs("\n", stdout);
		}
	}
	return 0;
}
