/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:26:22 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/22 00:57:25 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_up(t_data *data)
{
	t_config *g;

	g = data->g;
	g->ul[Y] += 10 * g->canva_s / (g->res - 1);
	if (g->set)
		julia_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	move_down(t_data *data)
{
	t_config *g;

	g = data->g;
	g->ul[Y] -= 10 * g->canva_s / (g->res - 1);
	if (g->set)
		julia_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	move_left(t_data *data)
{
	t_config *g;

	g = data->g;
	g->ul[X] -= 10 * g->canva_s / (g->res - 1);
	if (g->set)
		julia_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	move_right(t_data *data)
{
	t_config *g;

	g = data->g;
	g->ul[X] += 10 * g->canva_s / (g->res - 1);
	if (g->set)
		julia_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
