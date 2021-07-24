/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:26:22 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/24 14:44:47 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_up(t_data *data)
{
	t_config	*g;

	g = data->g;
	g->ul[Y] += 10 * g->factor;
	g->center[Y] += 10 * g->factor;
	if (g->set > 0)
		julia_loop(data);
	else if (g->set < 0)
		burning_ship_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	move_down(t_data *data)
{
	t_config	*g;

	g = data->g;
	g->ul[Y] -= 10 * g->factor;
	g->center[Y] -= 10 * g->factor;
	if (g->set > 0)
		julia_loop(data);
	else if (g->set < 0)
		burning_ship_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	move_left(t_data *data)
{
	t_config	*g;

	g = data->g;
	g->ul[X] -= 10 * g->factor;
	g->center[X] -= 10 * g->factor;
	if (g->set > 0)
		julia_loop(data);
	else if (g->set < 0)
		burning_ship_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	move_right(t_data *data)
{
	t_config	*g;

	g = data->g;
	g->ul[X] += 10 * g->factor;
	g->center[X] += 10 * g->factor;
	if (g->set > 0)
		julia_loop(data);
	else if (g->set < 0)
		burning_ship_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
