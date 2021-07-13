/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:18:07 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/13 22:34:18 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int ft_atoi(const char **s)
{
	unsigned int tmp;
	int n;

	tmp = (unsigned)**s - '0';
	n = 0;
	while (tmp < 10)
	{
		n = n * 10 + tmp;
		++(*s);
		tmp = (unsigned)**s - '0';
	}
	return (n);
}

static void error_config(const char *s, t_config *g)
{
	printf("\e[38;5;196mError:\e[m\n");
	printf("%s\n", s);
	if (g)
		free(g);
	exit(0);
}

static void up_config(const char *s, t_config *g)
{
	if (*s)
	{
		while (*s == ' ')
			++s;
		if ((unsigned char)*s - '0'  < 10)
			g->rgb[0] = ft_atoi(&s);
		else
			error_config("Color 1: the color must be defined by 3 numbers", g);
		while (*s == ' ')
			++s;
		if ((unsigned char)*s - '0'  < 10)
			g->rgb[1] = ft_atoi(&s);
		else
			error_config("Color 2: the color must be defined by 3 number", g);
		while (*s == ' ')
			++s;
		if ((unsigned char)*s - '0'  < 10)
			g->rgb[2] = ft_atoi(&s);
		else
			error_config("Color 3: the color must be defined by a number", g);
	}
	g->res[X] = 1920;
	g->res[Y] = 1080;
}

static int rgb_to_color(float *rgb)
{
	return ((int)rgb[R] << 16 | (int)rgb[G] << 8 | (int)rgb[B]);
}

static void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + ( y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int exit_and_free(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	if (data->g)
		free(data->g);
	if (data)
		free(data);
	exit(1);
	return (1);
}

static int get_keypress(int key, t_data *data)
{
	if (key == 65307)
		return (exit_and_free(data));
	return (1);
}

void render(const char *s, t_data *data)
{
	t_config *g;
	int color;
	int i;
	int j;
	float bg[3];
	g = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		error_config("Memory could not be allocated.", g);
	g = malloc(sizeof(t_config));
	if (!g)
		error_config("Memory could not be allocated.", g);
	data->g = g;
	up_config(s, g);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, g->res[X], g->res[Y], "fractol");
	data->img = mlx_new_image(data->mlx, g->res[X], g->res[Y]);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	j = g->res[Y];
	while (j)
	{
		i = 0;
		while (i < g->res[X])
		{
			//fractol magic
			bg[R] = g->rgb[R] * (float)i / (g->res[X] - 1);
			bg[G] = g->rgb[G] * (float)j / (g->res[Y] - 1);
			bg[B] = g->rgb[B] * 0.25;
			color = rgb_to_color(bg);
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		--j;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 2, 1L<<0, get_keypress, data);
	mlx_hook(data->win, 33, 1L<<17, exit_and_free, data);
	mlx_loop(data->mlx);
}
