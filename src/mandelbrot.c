/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:29:53 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/24 12:30:21 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_magic(t_config *g, float cr, float ci)
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
	tmp = sqrtf(pow(cr - 0.25, 2) + pow(ci, 2));
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
		color = g->rgb[n % g->n_colors];
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
			color = mandelbrot_magic(g, g->ul[X] + (float)i * g->factor,
					g->ul[Y] - (float)j * g->factor);
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		++j;
	}
}
