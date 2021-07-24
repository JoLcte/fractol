/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:30:33 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/24 12:30:56 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship_magic(t_config *g, float cr, float ci)
{
	float		z[2];
	float		tmp;
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
		color = g->rgb[n % g->n_colors];
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
			color = burning_ship_magic(g, g->ul[X] + (float)i * g->factor,
					-(g->ul[Y] - (float)j * g->factor));
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}
