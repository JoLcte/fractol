/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:51:38 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/20 17:02:59 by jlecomte         ###   ########.fr       */
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

int get_mouse_scroll(int key, t_data *data)
{
	int i;
	int j;
	float factor;
	int color;

	//factor = 1 / data->g->res[Y];
	factor = 0.45;
if (key == 5)
	{
		j = 0;
		while (j < data->g->res[Y])
		{
			i = 0;
			while (i < data->g->res[X])
			{
				if (data->g->set == 'j')
					color = julia_magic(data->g, -1.5 * 0.5 + (float)i * factor * 0.5, 1.5 * 0.5 - (float)j * factor * 0.5);
				else if (data->g->set == 'm')
					color = mandelbrot_magic(data->g, -2.5 * 0.5 + (float)i * factor * 0.5, 1.5 * 0.5 - (float)j * factor * 0.5);
				my_mlx_pixel_put(data, i, j, color);
				++i;
			}
			++j;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_hook(data->win, 2, 1L<<0, get_keypress, data);
		mlx_hook(data->win, 4, 4L<<0, get_mouse_scroll, data);
		mlx_hook(data->win, 33, 1L<<17, exit_and_free, data);
		mlx_loop(data->mlx);
	}
	return (1);
}

int get_keypress(int key, t_data *data)
{
	if (key == 65307)
		return (exit_and_free(data));
	else
		printf("key = %d\n", key);
	return (1);
}
