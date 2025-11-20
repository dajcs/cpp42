/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:56:04 by anemet            #+#    #+#             */
/*   Updated: 2025/11/20 15:38:32 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

# include <stdlib.h>	// malloc, calloc, free, atoi
# include <unistd.h>	// read
# include <stdio.h> 	// putchar

// struct to hold the game state
typedef struct s_game
{
	int width;
	int height;
	int iterations;
	char **board;
	char **next_board;
}	t_game;


// function prototypes

// main.c
void ft_putstr(char *str);
int ft_strlen(char *str);

// board.c
char **create_board(int width, int height);
void free_board(char **board, int height);
void print_board(t_game *game);

// input.c
int parse_initial_state(t_game *game);

// simulation.c
void run_simulation(t_game *game);

#endif
