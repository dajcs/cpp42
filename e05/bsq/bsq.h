/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:23:43 by anemet            #+#    #+#             */
/*   Updated: 2025/11/21 11:09:53 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <fcntl.h>
#include <stdio.h>	// fopen, fclose, getline, fscanf,
#include <stdlib.h>	// malloc, free,
// #include <unistd.h>

typedef struct s_map
{
	int		rows;	// nr of rows in the map
	int		cols;	// nr of cols in the map
	char	empty;	// empty char in the map
	char	obs;	// obstacle char in the map
	char	full;	// biggest square (solution) char in the map
	char	**grid;	// 2D grid storing the map
	int		x0;		// bsq top left corner x0
	int		y0;		// bsq top left corner y0
	int		size;	// bsq size
}	t_map;

// === utils ===
int	ft_strlen(char *s);
int	is_printable(char c0);
