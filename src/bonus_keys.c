/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:00:56 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/23 00:16:35 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void switch_palette(t_data *data)
{
	t_config *g;

	g = data->g;
	if (g->n_colors == 16)
		rgb_palette(g, 2);
	else if (g->n_colors == 29)
		rgb_palette(g, 1);
	if (g->set > 0)
		julia_loop(data);
	else if (g->set < 0)
		burning_ship_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	change_julia(t_data *data, int key)
{
	t_config *g;

	g = data->g;
	if (key == 120)
	{
		g->c[R] = -0.51;
		g->c[I] = 0.52;
	}
	else if (key == 122)
	{
		g->c[R] = 0.285;
		g->c[I] = 0.01;
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
