/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:24:11 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/22 00:41:38 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void zoom_in(int x, int y, t_data *data)
{
	t_config *g;
	float tmp;

	g = data->g;
	tmp = g->canva_s * 0.8 - g->canva_s;
	g->ul[X] *= 0.8;
	g->ul[Y] *= 0.8;
	g->ul[X] += x * tmp / (g->res - 1);
	g->ul[Y] += y * tmp / (g->res - 1);
	g->canva_s *= 0.8;
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
	g->ul[X] += x * tmp / (g->res - 1);
	g->ul[Y] += y * tmp / (g->res - 1);
	g->canva_s *= 1.1;
	g->factor = g->canva_s / (g->res - 1);
	if (g->set)
		julia_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
