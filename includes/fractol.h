/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:28:26 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/14 17:48:39 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define X 0
# define Y 1
# define R 0
# define I 1
# define red 1
# define green 2
# define blue 3

/*
 ** DATA
 */

typedef struct s_config
{
	float c[2];
	int rgb[64];
} t_config;

typedef struct s_data
{
	t_config *g;
	void *mlx;
	void *img;
	char *addr;
	void *win;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

/*
**	PARSING
*/

void	check_arg(char **str);
int		ft_atoi(const char **s);
void	up_config(const char *s, t_config *g);


/*
**	ERROR
*/

void	error_arg(const char *s);
void	error_config(const char *s, t_config *g);

/*
**	MLX
*/

int		rgb_to_color(float *rgb);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_and_free(t_data *data);
int		get_keypress(int key, t_data *data);

/*
**	FRACTOL
*/

void render(const char *s, t_data *data);

#endif
