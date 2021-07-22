/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:24:11 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/22 14:38:37 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void zoom_in(int x, int y, t_data *data)
{
	printf("on a bouge la molette\n");
	t_config *g;
	float tmp;

	g = data->g;
	tmp = g->canva_s * 0.9 - g->canva_s;
	g->canva_s *= 0.9;
	g->factor = g->canva_s / (g->res);
	g->mouse_pos[X] += (g->res * 0.5 - x) * tmp / (g->res);
	g->mouse_pos[Y] -= (g->res * 0.5 - y) * tmp / (g->res);
	g->ul[X] = g->mouse_pos[X] - (g->canva_s * 0.5);
	g->ul[Y] = g->mouse_pos[Y] + (g->canva_s * 0.5);
	if (g->set > 0)
		julia_loop(data);
	else if (g->set < 0)
		burning_ship_loop(data);
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
	g->canva_s *= 1.1;
	g->factor = g->canva_s / (g->res);
	g->mouse_pos[X] += (g->res * 0.5 - x) * tmp / (g->res);
	g->mouse_pos[Y] -= (g->res * 0.5 - y) * tmp / (g->res);
	g->ul[X] = g->mouse_pos[X] - (g->canva_s * 0.5);
	g->ul[Y] = g->mouse_pos[Y] + (g->canva_s * 0.5);
	if (g->set > 0)
		julia_loop(data);
	else if (g->set < 0)
		burning_ship_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
