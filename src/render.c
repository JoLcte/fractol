/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:18:07 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/22 22:20:19 by jlecomte         ###   ########.fr       */
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
		color = g->rgb[n % g->n_colors];
	return (color);
}

void mandelbrot_loop(t_data *data)
{
	t_config *g;
	int i;
	int j;
	int color;

	g = data->g;
	j = 0;
	while (j < g->res)
	{
		i = 0;
		while (i < g->res)
		{
			color = mandelbrot_magic(g, g->ul[X] + (float)i * g->factor,
				g->ul[Y] - (float)j * g->factor);
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}


int	burning_ship_magic(t_config *g, float cr, float ci)
{
	float z[2];
	float tmp;
	int color;
	const int n_max = 1000;
	int n;

	z[X] = 0.0;
	z[Y] = 0.0;
	n = 0;
	color = 0;
	while (pow(z[X], 2) + pow (z[Y], 2) <= 4 && n++ <= n_max)
	{
		tmp = fabs(pow(z[X], 2) - pow(z[Y], 2) + cr);
		z[Y] = fabs(2 * z[X] * z[Y] + ci);
		z[X] = tmp;
	}
	if (n < n_max)
		color = g->rgb[n % g->n_colors];
	return (color);
}

void burning_ship_loop(t_data *data)
{
	t_config *g;
	int i;
	int j;
	int color;

	g = data->g;
	j = 0;
	while (j < g->res)
	{
		i = 0;
		while (i < g->res)
		{
			color = burning_ship_magic(g, g->ul[X] + (float)i * g->factor,
				-(g->ul[Y] - (float)j * g->factor));
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
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
		color = g->rgb[n % g->n_colors];
	return (color);
}

void julia_loop(t_data *data)
{
	t_config *g;
	int i;
	int j;
	int color;

	g = data->g;
	j = 0;
	while (j < g->res)
	{
		i = 0;
		while (i < g->res)
		{
			color = julia_magic(g, g->ul[X] + (float)i * g->factor,
				g->ul[Y] - (float)j * g->factor);
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}

