/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:28:26 by jlecomte          #+#    #+#             */
/*   Updated: 2021/10/05 15:35:38 by jlecomte         ###   ########.fr       */
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

# include <pthread.h>

/*
**	CLEARER ARRAYS
*/

# define X 0
# define Y 1
# define R 0
# define I 1

/*
**	FRACTOL TYPES
*/

# define JUL 1
# define MDL 0
# define BS -1

/*
**	COLORS HANDLE
**	Note: N_INDEXES must be <= N_COLORS and >= number of colors in palette
*/

# define N_PALETTES 5
# ifndef N_INDEXES
#  define N_INDEXES 16
# endif
# ifndef N_COLORS
#  define N_COLORS 64
# endif

# define N_THREADS 4

/*
**	SET YOUR JULIA
*/

# ifndef CR
#  define CR 0.285
# endif
# ifndef CI
#  define CI 0.010
# endif

/*
**	DATA
*/

typedef struct s_gradient
{
	int	**palette;
	int	*indexes;
}	t_gradient;

typedef struct s_rgb
{
	double r;
	double g;
	double b;
}	t_rgb;

typedef struct s_config
{
	t_gradient *gradient;
	double	c[2];
	double	center[2];
	double	ul[2];
	double	canva_s;
	double	factor;
	double	res;
	int		**rgb;
	int 	live_palette;
	int	size_palette;
	int		set;
	int		shift;
}	t_config;

typedef struct s_data
{
	t_config	*g;
	char		*addr;
	void		*img;
	void		*mlx;
	void		*win;
	int			bpp;
	int			line_len;
	int			endian;
}	t_data;

typedef struct s_tdata
{
	t_data	*data;
	int	id;
}	t_tdata;


/*
**	PARSING
*/

int		check_arg(const char *s1, const char *s2, int n);
void	init_g(t_config *g);
void	init_palettes(t_config *g);
void	init_spec(t_config *g, int set);
void	init_start(t_config *g);
void	init_indexes(int *indexes, int size, int n);
void	fill_gradient(t_config *g, int size, int n, int *rgb);
void	lerp_hexa(int c1, int c2, int n, int *rgb);
void	parse(t_config *g, char *s);

/*
**	ERROR
*/

void	error_arg(const char *s);
void	error_colors(const char *s, t_config *g);
void	error_config(const char *s, t_data *data);
void	error_type(void);
void	print_help(t_config *g, int key);

/*
**	COLORS
*/

void	palette_0(int *palette);
void	palette_1(int *palette);
void	palette_2(int *palette);
void	palette_3(int *palette);
void	palette_4(int *palette);

/*
**	MLX
*/

void	change_burning_ship(t_data *data);
void	change_julia(t_data *data, int key);
void	change_palette(t_data *data);
void	color_shift(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_and_free(t_data *data);
int		get_keypress(int key, t_data *data);
int		get_mouse_scroll(int key, int x, int y, t_data *data);
void	move_all(int key, t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_up(t_data *data);
void	move_in(t_data *data);
void	move_out(t_data *data);
void	zoom_in(int x, int y, t_data *data);
void	zoom_out(int x, int y, t_data *data);

/*
**	FRACTOL
*/

void	julia_loop(t_data *data);
int		julia_magic(t_config *g, double a, double b);
void	mandelbrot_loop(t_data *data);
int		mandelbrot_magic(t_config *g, double cr, double ci);
void	burning_ship_loop(t_data *data);
int		burning_ship_magic(t_config *g, double cr, double ci);
void	rgb_palette(t_config *g, int n);
void	switch_palette(t_data *data);
void	fract_ol(t_data *data);
void	render(t_data *data);

/*
**	MULTITHREADING
*/

void	t_render(t_data *data);
void	*tjulia_loop(void *tdata);
void	*tmandelbrot_loop(void *tdata);
void	*tburning_ship_loop(void *tdata);

#endif
