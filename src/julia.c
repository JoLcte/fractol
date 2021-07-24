/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:28:56 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/24 12:29:45 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_magic(t_config *g, float a, float b)
{
	float		tmp;
	const int	n_max = 1000;
	int			n;
	int			color;

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
			color = julia_magic(g, g->ul[X] + (float)i * g->factor,
					g->ul[Y] - (float)j * g->factor);
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}
