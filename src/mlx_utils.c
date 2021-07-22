/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:51:38 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/22 15:16:39 by jlecomte         ###   ########.fr       */
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
	mlx_do_key_autorepeaton(data->mlx);
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
	printf("key = %d\n", key);
	if (key == 65307)
		return (exit_and_free(data));
	else if (key == 65362 || key == 119)
		move_up(data);
	else if (key == 65364 || key == 115)
		move_down(data);
	else if (key == 65361 || key == 97)
		move_left(data);
	else if (key == 65363 || key == 100)
		move_right(data);
	return (1);
}
