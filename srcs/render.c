/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:18:07 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/20 18:51:07 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_magic(t_config *g, float cr, float ci)
{
	float a;
	float b;
	float tmp;
	int color;
	const int n_max = 1000;
	int n;
	
	n = 0;
	a = 0.0;
	b = 0.0;
	color = 0;
	(void)g;
	while (pow(a, 2) + pow (b, 2) <= 4 && n++ <= n_max)
	{
		tmp = pow(a, 2) - pow(b, 2) + cr;
		b = 2 * a * b + ci;
		a = tmp;
	}
	if (n < n_max)
		//color = n * 16777215 / n_max;
		color = g->rgb[n % 16];
	return (color);
}

int	julia_magic(t_config *g, float a, float b)
{
	int color;
	int n_max = 1000;
	int n;
	float tmp;

	n = 0;
	n_max = 1000;
	color = 0;
	while (pow(a, 2) + pow(b, 2) <= 4 && n++ <= n_max)
	{
		tmp = pow(a, 2) - pow(b, 2) + g->c[R];
		b = 2 * a * b + g->c[I];
		a = tmp;
	}
	if (n < n_max)
		//color = n * 16777215 / n_max;
		color = g->rgb[n % 16];
	return (color);
}

void	render(t_data *data)
{
	int color;
	int i;
	int j;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->g->res[X], data->g->res[Y], "fractol");
	data->img = mlx_new_image(data->mlx, data->g->res[X], data->g->res[Y]);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	j = 0;
	while (j < data->g->res[Y])
	{
		i = 0;
		while (i < data->g->res[X])
		{
			if (data->g->set == 'j')
				color = julia_magic(data->g, data->g->ul[X] + (float)i * data->g->factor_x, data->g->ul[Y] - (float)j * data->g->factor_y);
			else if (data->g->set == 'm')
				color = mandelbrot_magic(data->g, data->g->ul[X] + (float)i * data->g->factor_x, data->g->ul[Y] - (float)j * data->g->factor_y);
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 2, 1L<<0, get_keypress, data);
	mlx_hook(data->win, 4, 4, get_mouse_scroll, data);
	
	mlx_hook(data->win, 33, 1L<<17, exit_and_free, data);
	mlx_loop(data->mlx);
}
