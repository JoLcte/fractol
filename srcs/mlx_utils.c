/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:51:38 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/18 21:29:58 by jlecomte         ###   ########.fr       */
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

	dst = data->addr + (y * data->line_length +
		       x * (data->bits_per_pixel / 8));
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

int get_keypress(int key, t_data *data)
{
	if (key == 65307)
		return (exit_and_free(data));
	return (1);
}
