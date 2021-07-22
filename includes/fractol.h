/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:28:26 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/23 00:12:27 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"
# include <stdint.h>
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
	float center[2];
	float ul[2];
	int rgb[29];
	float canva_s;
	float factor;
	float res;
	int n_colors;
	int set;
} t_config;

typedef struct s_data
{
	t_config *g;
	char *addr;
	void *img;
	void *mlx;
	void *win;
	int bpp;
	int line_len;
	int endian;
} t_data;

/*
**	PARSING
*/

int	check_arg(const char *s1, const char *s2, int n);
void	init_g(t_config *g);
void	parse(t_config *g, char *s);


/*
**	ERROR
*/

void	error_arg(const char *s);
void	error_config(const char *s, t_data *data);
void	error_type(void);

/*
**	MLX
*/

void	change_julia(t_data *data, int key);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_and_free(t_data *data);
int		get_keypress(int key, t_data *data);
int		get_mouse_scroll(int key, int x, int y, t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_up(t_data *data);
void	zoom_in(int x, int y, t_data *data);
void	zoom_out(int x, int y, t_data *data);
void	print_help(void);

/*
**	FRACTOL
*/

void	julia_loop(t_data *data);
int		julia_magic(t_config *g, float a, float b);
void	mandelbrot_loop(t_data *data);
int		mandelbrot_magic(t_config *g, float cr, float ci);
void	burning_ship_loop(t_data *data);
int		burning_ship_magic(t_config *g, float cr, float ci);
void	rgb_palette(t_config *g, int n);
void	switch_palette(t_data *data);
void	render(t_data *data);

#endif
