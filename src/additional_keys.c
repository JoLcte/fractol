/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:00:56 by jlecomte          #+#    #+#             */
/*   Updated: 2021/10/07 15:13:00 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_shift(t_data *data)
{
	data->g->shift = (data->g->shift + 1) % data->g->size_palette;
	if (data->g->set == JUL)
		julia_loop(data);
	else if (data->g->set == MDL)
		mandelbrot_loop(data);
	else
		burning_ship_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	change_palette(t_data *data)
{
	t_config	*g;

	g = data->g;
	g->shift = 0;
	if (g->live_palette < N_PALETTES - 1)
	{
		g->size_palette = N_COLORS;
		++g->live_palette;
	}
	else
	{
		g->size_palette = 16;
		g->live_palette = 0;
	}
	//render(data);
	t_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	change_julia(t_data *data, int key)
{
	t_config	*g;

	g = data->g;
	if (key == 120)
	{
		init_start(g);
		g->c[R] = -0.785;
		g->c[I] = 0.152;
	}
	else if (key == 122)
	{
		init_start(g);
		g->c[R] = CR;
		g->c[I] = CI;
	}
	else if (key == 105)
		g->c[R] += 0.001;
	else if (key == 106)
		g->c[I] += 0.001;
	else if (key == 107)
		g->c[R] -= 0.001;
	else
		g->c[I] -= 0.001;
	julia_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	change_burning_ship(t_data *data)
{
	t_config	*g;

	g = data->g;
	g->canva_s = 0.1;
	g->factor = g->canva_s / g->res;
	g->ul[X] = -1.8000;
	g->ul[Y] = 0.0196;
	g->center[X] = g->ul[X] + g->canva_s / 2;
	g->center[Y] = g->ul[Y] - g->canva_s / 2;
	burning_ship_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
