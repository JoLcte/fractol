/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:28:56 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/28 00:10:23 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_magic(t_config *g, double a, double b)
{
	double		tmp;
	const int	n_max = 1000;
	int			n;
	int			color;

	n = 0;
	color = 0;
	while (a * a + b * b <= 4 && n++ <= n_max)
	{
		tmp = a * a - b * b + g->c[R];
		b = 2 * a * b + g->c[I];
		a = tmp;
	}
	if (n < n_max)
		color = g->rgb[g->live_palette][n % g->size_palette];
	return (color);
}

void	julia_loop(t_data *data)
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
			color = julia_magic(g, g->ul[X] + (double)i * g->factor,
					-(g->ul[Y] - (double)j * g->factor));
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}

static void	tjulia(t_data *data, int *val, int *max)
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
			color = julia_magic(g, g->ul[X] + (double)i * g->factor,
					-(g->ul[Y] - (double)j * g->factor));
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}

static void	tjulia_bis(t_tdata *th_data, int *val, int *max)
{
	t_config	*g;

	g = th_data->data->g;
	if (th_data->id == 0)
	{
		val[Y] = 0;
		max[Y] = g->res * 0.5;
		val[X] = 0;
		max[X] = g->res * 0.5;
		tjulia(th_data->data, val, max);
	}
	else if (th_data->id == 1)
	{
		val[Y] = 0;
		max[Y] = g->res * 0.5;
		val[X] = g->res * 0.5;
		max[X] = g->res;
		tjulia(th_data->data, val, max);
	}
}

void	*tjulia_loop(void *tdata)
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
		tjulia(th_data->data, val, max);
	}
	else if (th_data->id == 3)
	{
		val[Y] = g->res * 0.5;
		max[Y] = g->res;
		val[X] = g->res * 0.5;
		max[X] = g->res;
		tjulia(th_data->data, val, max);
	}
	tjulia_bis(th_data, val, max);
	pthread_exit(NULL);
}
