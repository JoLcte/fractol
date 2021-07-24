/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:24:11 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/24 12:36:17 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_data *data)
{
	t_config	*g;
	float		tmp;

	g = data->g;
	tmp = g->canva_s * 0.9 - g->canva_s;
	g->canva_s *= 0.9;
	g->factor = g->canva_s / (g->res);
	g->center[X] -= (x - g->res * 0.5) * tmp / (g->res);
	g->center[Y] += (y - g->res * 0.5) * tmp / (g->res);
	g->ul[X] = g->center[X] - (g->canva_s * 0.5);
	g->ul[Y] = g->center[Y] + (g->canva_s * 0.5);
	if (g->set > 0)
		julia_loop(data);
	else if (g->set < 0)
		burning_ship_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	zoom_out(int x, int y, t_data *data)
{
	t_config	*g;
	float		tmp;

	g = data->g;
	tmp = g->canva_s * 1.1 - g->canva_s;
	g->canva_s *= 1.1;
	g->factor = g->canva_s / (g->res);
	g->center[X] -= (x - g->res * 0.5) * tmp / (g->res);
	g->center[Y] += (y - g->res * 0.5) * tmp / (g->res);
	g->ul[X] = g->center[X] - (g->canva_s * 0.5);
	g->ul[Y] = g->center[Y] + (g->canva_s * 0.5);
	if (g->set > 0)
		julia_loop(data);
	else if (g->set < 0)
		burning_ship_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
