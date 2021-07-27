/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:29:53 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/28 00:13:10 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_magic(t_config *g, double cr, double ci)
{
	double		z[2];
	double		tmp;
	const int	n_max = 1000;
	int			n;
	int			color;

	z[X] = 0.0;
	z[Y] = 0.0;
	n = 0;
	color = 0;
	tmp = sqrt(pow(cr - 0.25, 2) + pow(ci, 2));
	if (cr <= tmp - 2 * pow(tmp, 2) + 0.25)
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
		color = g->rgb[g->live_palette][n % g->size_palette];
	return (color);
}

void	mandelbrot_loop(t_data *data)
{
	t_config	*g;
	int			i;
	int			j;
	int			color;

	g = data->g;
	j = 0;
	while (j < g->res)
	{
		i = 0;
		while (i < g->res)
		{
			color = mandelbrot_magic(g, g->ul[X] + (double)i * g->factor,
					-(g->ul[Y] - (double)j * g->factor));
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}

static void	tmandelbrot(t_data *data, int *val, int *max)
{
	t_config	*g;
	int			i;
	int			j;
	int			color;

	g = data->g;
	j = val[Y];
	while (j < max[Y])
	{
		i = val[X];
		while (i < max[X])
		{
			color = mandelbrot_magic(g, g->ul[X] + (double)i * g->factor,
					-(g->ul[Y] - (double)j * g->factor));
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}

static void	tmandelbrot_bis(t_tdata *th_data, int *val, int *max)
{
	t_config	*g;

	g = th_data->data->g;
	if (th_data->id == 0)
	{
		val[Y] = 0;
		max[Y] = g->res * 0.5;
		val[X] = 0;
		max[X] = g->res * 0.5;
		tmandelbrot(th_data->data, val, max);
	}
	else if (th_data->id == 1)
	{
		val[Y] = 0;
		max[Y] = g->res * 0.5;
		val[X] = g->res * 0.5;
		max[X] = g->res;
		tmandelbrot(th_data->data, val, max);
	}
}

void	*tmandelbrot_loop(void *tdata)
{
	t_tdata		*th_data;
	t_config	*g;
	int			val[2];
	int			max[2];

	th_data = (t_tdata *)tdata;
	g = th_data->data->g;
	if (th_data->id == 2)
	{
		val[Y] = g->res * 0.5;
		max[Y] = g->res;
		val[X] = 0;
		max[X] = g->res * 0.5;
		tmandelbrot(th_data->data, val, max);
	}
	else if (th_data->id == 3)
	{
		val[Y] = g->res * 0.5;
		max[Y] = g->res;
		val[X] = g->res * 0.5;
		max[X] = g->res;
		tmandelbrot(th_data->data, val, max);
	}
	tmandelbrot_bis(th_data, val, max);
	pthread_exit(NULL);
}
