/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:29:15 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/28 00:41:55 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_indexes(int *indexes, int size, int n)
{
	const int	scalar = size / (n - 1);
	int			i;

	i = 0;
	while (i < n - 1)
	{
		indexes[i] = scalar * i;
		++i;
	}
	indexes[i] = size - 1;
}

void	lerp_hexa(int c1, int c2, int t, int *rgb)
{
	t_rgb			a;
	t_rgb			b;
	t_rgb			res;
	const double	inv_n = 1.0 / t;
	int				i;

	a = (t_rgb){c1 >> 16 & 0xFF, c1 >> 8 & 0xFF, c1 & 0xFF};
	b = (t_rgb){c2 >> 16 & 0xFF, c2 >> 8 & 0xFF, c2 & 0xFF};
	i = 0;
	if (c1 == c2)
		while (i < t)
			rgb[i++] = c1;
	else
	{
		while (i < t)
		{
			res.r = a.r + (double)i * inv_n * (b.r - a.r);
			res.g = a.g + (double)i * inv_n * (b.g - a.g);
			res.b = a.b + (double)i * inv_n * (b.b - a.b);
			rgb[i] = ((int)res.r << 16) | ((int)res.g << 8)
				| ((int)res.b);
			++i;
		}
	}
}

void	fill_gradient(t_config *g, int live, int n, int *rgb)
{
	int	i;
	int	*indexes;
	int	*colors;

	colors = g->gradient->palette[live];
	indexes = g->gradient->indexes;
	i = 0;
	while (i + 1 < n)
	{
		lerp_hexa(colors[i], colors[i + 1],
			indexes[i + 1] - indexes[i], &rgb[indexes[i]]);
		++i;
	}
	rgb[N_COLORS - 1] = colors[i];
}

void	init_palettes(t_config *g)
{
	t_gradient	*p;
	int			i;

	p = g->gradient;
	palette_0(p->palette[0]);
	palette_1(p->palette[1]);
	palette_2(p->palette[2]);
	palette_3(p->palette[3]);
	palette_4(p->palette[4]);
	i = 1;
	while (i < N_PALETTES)
	{
		fill_gradient(g, i, N_INDEXES, g->rgb[i]);
		++i;
	}
	i = 0;
	while (i < 16)
	{
		g->rgb[0][i] = p->palette[0][i];
		++i;
	}
	g->live_palette = 0;
	g->size_palette = 16;
}
