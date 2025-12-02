/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:55:09 by anemet            #+#    #+#             */
/*   Updated: 2025/12/02 10:20:13 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Submitted files: *.c, *.h
Allowed functions: atoi, read, putchar, malloc, calloc, realloc, free

Prototype of program: ./life width height iterations

Width and height are the dimensions of the board and iterations
is the number of iterations of the game of life.

The initial configuration of the board will be drawn by a sequence
of commands in the standard input.

Imagine a pen starting in the top left corner of the board.
Each command is one of these characters:
	w a s d -> move the pen up, left, bottom, and right.
	x 		-> lift or lower the pen in order to start or stop drawing.

pen no move outside board and stays still if a command ask for it.
pen do nothing in case of invalid command.

once end of file is reached, your program must simulate a game of life on
board and print the result in stdout (each cell alive will be represented l
the character '0' and each dead cell will be represented by a space)
each cell outside of the array will be considered dead.

Examples:

$> echo 'sdxddssaaww' | ./a.out 5 5 0 | cat -e
     $
 000 $
 0 0 $
 000 $
     $
$> echo 'sdxssdswdxdddxsaddawxwdxwaa' | ./a.out 10 6 0 | cat -e
          $
 0   000  $
 0     0  $
 000  0   $
  0  000  $
          $
$> echo 'dxss' | ./a.out 3 3 0 | cat -e
 0 $
 0 $
 0 $
$> echo 'dxss' | ./a.out 3 3 1 | cat -e
   $
000$
   $
$> echo 'dxss' | ./a.out 3 3 2 | cat -e
 0 $
 0 $
 0 $

*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_game
{
	int width;
	int height;
	int iterations;
	char** grid;
	char** next_grid;
}	t_game;

// write string to stdout
void ft_putstr(char* str)
{
	for (int i = 0; str[i]; i++)
	{
		putchar(str[i]);
	}
}

void free_grid(char** grid, int height)
{
	if (grid)
	{
		for (int i = 0; i < height; i++)
		{
			if (grid[i])
			{
				free(grid[i]);
				grid[i] = NULL;
			}
		}
	}
	grid = NULL;
}

char** calloc_grid(int width, int height)
{
	char** grid;

	grid = calloc(height, sizeof(char *));
	if (!grid)
		return NULL;
	for (int i = 0; i < height; i++)
	{
		grid[i] = calloc(width, sizeof(char));
		if (!grid[i])
			return NULL;
	}
	return grid;
}


void parse_initial_state(t_game* game)
{
	char buf[1];
	int r = 0;
	int c = 0;
	int is_drawing = 0;

	// ssize_t read(int fildes, void *buf, size_t nbyte);
	// read 1 byte from STDIN until EOF
	while (read(STDIN_FILENO, buf, 1) > 0)
	{
		// move pen
		if (buf[0] == 'w' && r > 0)			// up
			r--;
		else if (buf[0] == 'a' && c > 0)	// left
			c--;
		else if (buf[0] == 's' && r < game->height - 1) // down
			r++;
		else if (buf[0] == 'd' && c < game->width - 1)	// right
			c++;
		// lift / lower the pen
		else if (buf[0] == 'x')
			is_drawing = !is_drawing;

		// mark live cell if is_drawing
		if (is_drawing)
			game->grid[r][c] = 1;
	}

}

// compute and return nr of alive neighbour cells
int get_neighbours(t_game* game, int r, int c)
{
	int nr, nc;         // neighbour row, col
	int nr_nbr = 0;     // nr alive neighbour cells

	for (int dr = -1; dr <= 1; dr++)
	{
		for (int dc = -1; dc <= 1; dc++)
		{
			nr = r + dr; // neighbour row
			nc = c + dc; // neighbour col
			if (nr >= 0 && nr < game->height &&	// row within limits
				nc >= 0 && nc < game->width &&	// col within limits
				!(r == nr && c == nc) &&		// skip own cell
				game->grid[nr][nc])				// check if nbr is alive
			{
				nr_nbr++;
			}
		}
	}
	return nr_nbr;
}

// compute next gen and put it in next_grid
/*
1.) Underpopulation:	A live cell with fewer than two live neighbors dies.
2.) Survival: 			A live cell with two or three live neighbors survives.
3.) Overpopulation: 	A live cell with more than three live neighbors dies.
4.) Reproduction: 		A dead cell with exactly three live neighbors becomes a live cell.
*/
void compute_next_gen(t_game* game)
{
	int nr_nbr;

	for (int r = 0; r < game->height; r++)
	{
		for (int c = 0; c < game->width; c++)
		{
			nr_nbr = get_neighbours(game, r, c);
			if (game->grid[r][c] == 1)
			{
				// Rule 1: underpopulation / Rule3: overpopulation
				if (nr_nbr < 2 || nr_nbr > 3)
				{
					game->next_grid[r][c] = 0;
				}
				// Rule 2: survival
				else
				{
					game->next_grid[r][c] = 1;
				}
			}
			else
			{
				// Rule 4: reproduction
				if (nr_nbr == 3)
				{
					game->next_grid[r][c] = 1;
				}
				// Rule 0: stays empty
				else
				{
					game->next_grid[r][c] = 0;
				}
			}
		}
	}
}

void run_simulation(t_game* game)
{
	char** tmp_grid;

	for (int i = 0; i < game->iterations; i++)
	{
		compute_next_gen(game);

		tmp_grid = game->grid;
		game->grid = game->next_grid;
		game->next_grid = tmp_grid;
	}
}

void print_grid(t_game *game)
{
	for (int r = 0; r < game->height; r++)
	{
		for (int c = 0; c < game->width; c++)
		{
			if(game->grid[r][c])
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

int main(int argc, char** argv)
{
	t_game game;

	game.grid = NULL;
	game.next_grid = NULL;

	// ./life width height iterations
	if (argc != 4)
	{
		ft_putstr("Use: ./life width height iterations\n");
		return 1;
	}
	game.width = atoi(argv[1]);
	game.height = atoi(argv[2]);
	game.iterations = atoi(argv[3]);

	if (game.width <= 0 || game.height <= 0 || game.iterations < 0)
	{
		ft_putstr("height and width should be > 0; iterations should be >= 0\n");
		return 1;
	}

	game.grid = calloc_grid(game.width, game.height);
	game.next_grid = calloc_grid(game.width, game.height);
	if (!game.grid || !game.next_grid)
	{
		ft_putstr("calloc grids failed\n");
		free_grid(game.grid, game.height);
		free_grid(game.next_grid, game.height);
		return 1;
	}

	parse_initial_state(&game);

	run_simulation(&game);

	// print final grid
	print_grid(&game);

	free_grid(game.grid, game.height);
	free_grid(game.next_grid, game.height);
}
