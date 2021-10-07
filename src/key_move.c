/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 00:26:22 by jlecomte          #+#    #+#             */
/*   Updated: 2021/10/06 12:09:17 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_up(t_data *data)
{
	t_config	*g;

	g = data->g;
	g->ul[Y] -= 64 * g->factor;
	g->center[Y] -= 64 * g->factor;
	//render(data);
	t_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	move_down(t_data *data)
{
	t_config	*g;

	g = data->g;
	g->ul[Y] += 64 * g->factor;
	g->center[Y] += 64 * g->factor;
	//render(data);
	t_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	move_left(t_data *data)
{
	t_config	*g;

	g = data->g;
	g->ul[X] -= 64 * g->factor;
	g->center[X] -= 64 * g->factor;
	//render(data);
	t_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	move_right(t_data *data)
{
	t_config	*g;

	g = data->g;
	g->ul[X] += 64 * g->factor;
	g->center[X] += 64 * g->factor;
	//render(data);
	t_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	move_all(int key, t_data *data)
{
	if (key == 65362 || key == 119)
		move_up(data);
	else if (key == 65364 || key == 115)
		move_down(data);
	else if (key == 65361 || key == 97)
		move_left(data);
	else if (key == 65363 || key == 100)
		move_right(data);
}
