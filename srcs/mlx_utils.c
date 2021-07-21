/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:51:38 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/21 23:57:46 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int rgb_to_color(uint8_t r, uint8_t g, uint8_t b)
{
	return ((int)r << 16 | (int)g << 8 | (int)b);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len +
			x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int exit_and_free(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	if (data)
		free(data);
	exit(1);
	return (1);
}

void zoom_in(int x, int y, t_data *data)
{
	t_config *g;
	float tmp;

	g = data->g;
	tmp = g->canva_s * 0.9 - g->canva_s;
	g->ul[X] *= 0.9;
	g->ul[Y] *= 0.9;
	g->ul[X] += (g->res * 0.5 - x) * tmp / (g->res - 1);
	g->ul[Y] += (g->res * 0.5 - y) * tmp / (g->res - 1);
	g->canva_s *= 0.9;
	g->factor = g->canva_s / (g->res - 1);
	if (g->set)
		julia_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void zoom_out(int x, int y, t_data *data)
{
	t_config *g;
	float tmp;

	g = data->g;
	tmp = g->canva_s * 1.1 - g->canva_s;
	g->ul[X] *= 1.1;
	g->ul[Y] *= 1.1;
	g->ul[X] += (g->res * 0.5 - x) * tmp / (g->res - 1);
	g->ul[Y] += (g->res * 0.5 - y) * tmp / (g->res - 1);
	g->canva_s *= 1.1;
	g->factor = g->canva_s / (g->res - 1);
	if (g->set)
		julia_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int get_mouse_scroll(int key, int x, int y, t_data *data)
{
	if (key == 5)
		zoom_in(x, y, data);
	else if (key == 4)
		zoom_out(x, y, data);
	return (1);
}

int get_keypress(int key, t_data *data)
{
	if (key == 65307)
		return (exit_and_free(data));
	else
		printf("key = %d\n", key);
	return (1);
}
