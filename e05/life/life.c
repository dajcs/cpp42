/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:01:57 by anemet            #+#    #+#             */
/*   Updated: 2025/11/20 15:44:32 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	--- game of life ---

Allowed functions: atoi, read, putchar, malloc, calloc, realloc, free

Starting board:

The pen starting in the top left corner of the board.
Each command is one of these characters:
- w a s d -> move the pen up, left, down, right by one cell
- x -> lift or lower the pen in order to start or stop drawing
- pen no move outside board and stays still if a command asks for it
- pen do nothing in case of invalid command

cell alive: '0'
cell dead: ' '

command:
	./life <width> <height> <nr_iterations>

	starting board from STDIN 'w' 'a' 's' 'd' 'x' inputs


Conway's game of life rules:
	1. underpopulation: live cell dies if nr_neighbours < 2
	2. survival: live cell with 2 or 3 neighbours survives
	3. overpopulation: live cell dies if nr_neigbours > 3
	4. reproduction: a dead cell becomes live cell if nr_neighbours == 3

*/



#include "life.h"

/*
	--- Utility Functions ---
*/

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

// write a tring to STDOUT using putchar
void ft_putstr(char *str)
{
	for (int i = 0; str[i]; i++)
		putchar(str[i]);
}


// --- Board Management ---

/*
	create_board()
	Allocates a 2D array (board) of given dimensions
	Uses calloc to initalize all cells to 0 (dead)
	Input: width, height
	Return: a pointer to the allocated board, or NULL on failure
*/
char **create_board(int width, int height)
{
	char **board;
	int i;

	// Allocate memory for the rows (pointers to char arrays)
	board = (char **)malloc(sizeof(char *) * height);
	if (!board)
		return NULL;
	i = 0;
	while (i < height)
	{
		// for each row allocated memory for the columns with calloc
		board[i] = (char *)calloc(width, sizeof(char));
		if (!board[i])
		{
			// free previous allocations
			while (i > 0)
				free(board[--i]);
			free(board);
			return NULL;
		}
		i++;
	}
	return board;
}

// free_board()
void free_board(char **board, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

// print_board()
void print_board(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->board[y][x] == 1)
				putchar('0');
			else
				putchar(' ');
			x++;
		}
		putchar('\n');
		y++;
	}
}

/*
	====== Parsing Initial State ==========
*/

/*
	parse_initial_state()
	Reads drawing commands from STDIN and initializes the board
	Handles pen movement and drawing logic
	Input: tgame *game
	Return: 0 on success, (1 on failure)
*/
int parse_initial_state(t_game *game)
{
	char buf[1];
	int px = 0; // pen x
	int py = 0; // pen y
	int is_drawing = 0; // 1 for pen down, starts with pen up

	// Read one character at a time from STDIN until EOF
	while (read(0, buf, 1) > 0)   // read(<fd>, <buf>, <nr_bytes>)
	{
		// Move pen UP, ensuring it doesn't go off the top of the board
		if (buf[0] == 'w' && py > 0)
			py--;
		// Move pen LEFT
		else if (buf[0] == 'a' && px > 0)
			px--;
		// Move pend DOWN
		else if (buf[0] == 's' && py < game->height - 1)
			py++;
		// Move pen RIGHT
		else if (buf[0] == 'd' && px < game->width - 1)
			px++;
		// Toggle drawing mode
		else if (buf[0] == 'x')
			is_drawing = !is_drawing;

		// if is_drawing => mark the current cell alive (1)
		if (is_drawing)
			game->board[py][px] = 1;
	}
	return 0;
}


/*
	========= Simulation Logic ==========
*/

/*
	count_live_neightbours()
	Counts the number of live neightbours for a given cell
		Cells outside the board are considered dead
	Input:
		t_game *game
		int x, int y - the (x,y) coordinates of the cell
	Return: nr of live neightbours
*/
int count_live_neighbours(t_game *game, int x, int y)
{
	int count = 0;
	int ny, nx; // neighbour coordinates

	for (int dy = -1; dy <= 1; dy++)
	{
		for (int dx = -1; dx <= 1; dx++)
		{
			// Skip the cell itself
			if (dx == 0 && dy == 0)
				continue;

			ny = y + dy;
			nx = x + dx;

			// Check if neigbour is within the board boundaries
			if (ny >= 0 && ny < game->height && nx >= 0 && nx < game->width)
			{
				// if neighbour is alive, increment the count
				count += game->board[ny][nx];
			}
		}
	}
	return count;
}

/*
	compute_next_generation()
	Computes one generation of the Game of Life
	It reads the `game->board` and writes the new state to `game->next_board`
	Input: t_game *game
*/
void compute_next_generation(t_game *game)
{
	int y, x, live_neighbours;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			live_neighbours = count_live_neighbours(game, x, y);

			// Rule 1 & 3: a live cell dies from under or overpopulation
			if (game->board[y][x] == 1 && (live_neighbours < 2 || live_neighbours > 3))
				game->next_board[y][x] = 0; // Dies
			// Rule 4: a dead cell with 3 live neighbours becomes alive
			else if (game->board[y][x] == 0 && live_neighbours == 3)
				game->next_board[y][x] = 1; // Resurrects
			// Rule 2: a live cell with 2 or 3 neighbours survives
			// Rule 0: a dead cell with live neighbours != 3 stays dead
			else
				game->next_board[y][x] = game->board[y][x]; // live or dead state remains unchanged

			x++;
		}
		y++;
	}
}

/*
	run_simulation()
	Runs the simulation for the specified number of iterations
*/
void run_simulation(t_game *game)
{
	int i = 0;
	char **temp_board;

	while (i < game->iterations)
	{
		// calculate the next state
		compute_next_generation(game);

		// swap the boards.
		// it is more efficient then copying
		temp_board = game->board;
		game->board = game->next_board;
		game->next_board = temp_board;
		i++;
	}
}

/*
	========== Main Function ===========
*/
int main (int argc, char **argv)
{
	t_game game;

	// check arguments
	if (argc != 4)
	{
		ft_putstr("Usage: ./life <width> <height> <iterations>\n");
		return 1;
	}
	// parse the arguments with `atoi`
	game.width = atoi(argv[1]);
	game.height = atoi(argv[2]);
	game.iterations = atoi(argv[3]);

	// validate the parsed arguments
	if (game.width <= 0 || game.height <= 0 || game.iterations < 0)
	{
		ft_putstr("Error: width, height must be > 0, iterations must be >= 0\n");
		return 1;
	}

	// Allocate memory for the current state and the next state boards
	game.board = create_board(game.width, game.height);
	game.next_board = create_board(game.width, game.height);
	if (!game.board || !game.next_board)
	{
		ft_putstr("Error: Memory allocation failed.\n");
		if(game.board)
			free_board(game.board, game.height);
		if (game.next_board)
			free_board(game.next_board, game.height);
		return 1;
	}

	// parse initial state
	parse_initial_state(&game);

	// run the simulation
	run_simulation(&game);

	// print final board
	print_board(&game);

	// Free all allocated memory before exiting
	free_board(game.board, game.height);
	free_board(game.next_board, game.height);

	return 0;
}
