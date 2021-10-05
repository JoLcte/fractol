/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:30:33 by jlecomte          #+#    #+#             */
/*   Updated: 2021/10/05 18:28:52 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship_magic(t_config *g, double cr, double ci)
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
	while (pow(z[X], 2) + pow (z[Y], 2) <= 4 && n++ <= n_max)
	{
		tmp = fabs(pow(z[X], 2) - pow(z[Y], 2) + cr);
		z[Y] = fabs(2 * z[X] * z[Y] + ci);
		z[X] = tmp;
	}
	if (n < n_max)
		color = g->rgb[g->live_palette][(n + g->shift)
			% g->size_palette];
	return (color);
}

void	burning_ship_loop(t_data *data)
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
			color = burning_ship_magic(g, g->ul[X] + (double)i * g->factor,
					(g->ul[Y] - (double)j * g->factor));
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}

static void	tbship(t_data *data, int *val, int *max)
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
			color = burning_ship_magic(g, g->ul[X] + (double)i * g->factor,
					-(g->ul[Y] - (double)j * g->factor));
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}

static void	tburning_ship_bis(t_tdata *th_data, int *val, int *max)
{
	t_config	*g;

	g = th_data->data->g;
	if (th_data->id == 0)
	{
		val[Y] = 0;
		max[Y] = g->res * 0.5;
		val[X] = 0;
		max[X] = g->res * 0.5;
		tbship(th_data->data, val, max);
	}
	else if (th_data->id == 1)
	{
		val[Y] = 0;
		max[Y] = g->res * 0.5;
		val[X] = g->res * 0.5;
		max[X] = g->res;
		tbship(th_data->data, val, max);
	}
}

void	*tburning_ship_loop(void *tdata)
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
		tbship(th_data->data, val, max);
	}
	else if (th_data->id == 3)
	{
		val[Y] = g->res * 0.5;
		max[Y] = g->res;
		val[X] = g->res * 0.5;
		max[X] = g->res;
		tbship(th_data->data, val, max);
	}
	tburning_ship_bis(th_data, val, max);
	pthread_exit(NULL);
}
