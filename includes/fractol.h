/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:28:26 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/21 23:49:33 by jlecomte         ###   ########.fr       */
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
	float ul[2];
	float mouse_pos[2];
	int rgb[16];
	float res;
	float factor;
	float canva_s;
	float set;
} t_config;

typedef struct s_data
{
	t_config *g;
	void *mlx;
	void *img;
	char *addr;
	void *win;
	int bpp;
	int line_len;
	int endian;
} t_data;

/*
**	PARSING
*/

void	check_arg(t_config *g, char **str);
int		ft_atoi(char **s);
double	get_double(char **s);
//void	up_config(const char *s, t_data *data);


/*
**	ERROR
*/

void	error_arg(const char *s);
void	error_config(const char *s, t_data *data);

/*
**	MLX
*/

int		rgb_to_color(uint8_t r, uint8_t g, uint8_t b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_and_free(t_data *data);
int		get_keypress(int key, t_data *data);
int		get_mouse_scroll(int key, int x, int y, t_data *data);
void	zoom_in(int x, int y, t_data *data);
void	zoom_out(int x, int y, t_data *data);

/*
**	FRACTOL
*/

void	julia_loop(t_data *data);
int		julia_magic(t_config *g, float a, float b);
void	mandelbrot_loop(t_data *data);
int		mandelbrot_magic(t_config *g, float cr, float ci);
void	render(t_data *data);

#endif
