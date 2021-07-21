/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:18:07 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/21 23:25:08 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_magic(t_config *g, float cr, float ci)
{
	float z[2];
	float p;
	float tmp;
	int color;
	const int n_max = 1000;
	int n;

	z[X] = 0.0;
	z[Y] = 0.0;
	n = 0;
	color = 0;
	p = sqrtf(pow(cr - 0.25, 2) + pow(ci, 2));
	if (cr <= p - 2 * pow(p, 2) + 0.25)
		return (color);
	if (pow(cr + 1, 2) + pow(ci, 2) <= 0.0625)
		return (color);
	while (pow(z[X], 2) + pow (z[Y], 2) <= 4 && n++ <= n_max)
	{
		tmp = pow(z[X], 2) - pow(z[Y], 2) + cr;
		z[Y] = 2 * z[X] * z[Y] + ci;
		z[X] = tmp;
	}
	if (n < n_max)
		color = g->rgb[n % 16];
	return (color);
}

int	julia_magic(t_config *g, float a, float b)
{
	int color;
	const int n_max = 1000;
	int n;
	float tmp;

	n = 0;
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

void julia_loop(t_data *data)
{
	int i;
	int j;
	int color;

	j = 0;
	while (j < data->g->res)
	{
		i = 0;
		while (i < data->g->res)
		{
			color = julia_magic(data->g, data->g->ul[X] + (float)i * data->g->factor, data->g->ul[Y] - (float)j * data->g->factor);
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}

void mandelbrot_loop(t_data *data)
{
	int i;
	int j;
	int color;

	j = 0;
	while (j < data->g->res)
	{
		i = 0;
		while (i < data->g->res)
		{
			color = mandelbrot_magic(data->g, data->g->ul[X] + (float)i * data->g->factor, data->g->ul[Y] - (float)j * data->g->factor);
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}

void	render(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->g->res, data->g->res, "fractol");
	data->img = mlx_new_image(data->mlx, data->g->res, data->g->res);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, 
		&data->line_len, &data->endian);
	if (data->g->set)
		julia_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 2, 1L<<0, get_keypress, data);
	mlx_hook(data->win, 4, 4L<<0, get_mouse_scroll, data);

	mlx_hook(data->win, 33, 1L<<17, exit_and_free, data);
	mlx_loop(data->mlx);
}
