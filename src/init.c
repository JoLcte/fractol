/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:47:58 by jlecomte          #+#    #+#             */
/*   Updated: 2021/10/07 16:18:12 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_spec(t_config *g, int set)
{
	if (set == JUL)
	{
		g->c[R] = CR;
		g->c[I] = CI;
	}
	else if (set == BS)
	{
		g->ul[X] -= 0.576;
		g->center[X] -= 0.576;
		g->ul[Y] -= 0.192;
		g->center[Y] -= 0.192;
	}
	else
	{
		g->center[X] -= 0.55;
		g->ul[X] -= 0.55;
	}
}

void	init_start(t_config *g)
{
	g->res = RESOL;
	g->canva_s = 3.0;
	g->ul[X] = -g->canva_s / 2.0;
	g->ul[Y] = g->canva_s / 2.0;
	g->center[X] = 0.0;
	g->center[Y] = 0.0;
	g->factor = g->canva_s / g->res;
	g->shift = 0;
}

static void	check_malloc(t_config *g, void **ptr, int size, int n)
{
	*ptr = malloc(size * n);
	if (!*ptr)
		error_colors("Memory could not be allocated.", g);
}

void	init_g(t_config *g)
{
	t_gradient	*gd;
	int			i;

	init_start(g);
	check_malloc(g, (void **)&g->gradient, sizeof(t_gradient), 1);
	gd = g->gradient;
	check_malloc(g, (void **)&gd->indexes, sizeof(int), N_INDEXES);
	check_malloc(g, (void **)&gd->palette, sizeof(int **), N_PALETTES);
	i = 0;
	while (i < N_PALETTES)
		check_malloc(g, (void **)&gd->palette[i++], sizeof(int), N_INDEXES);
	i = 0;
	check_malloc(g, (void **)&g->rgb, sizeof(int **), N_PALETTES);
	while (i < N_PALETTES)
		check_malloc(g, (void **)&g->rgb[i++], sizeof(int), N_COLORS);
	init_indexes(gd->indexes, N_COLORS, N_INDEXES);
	init_palettes(g);
	init_spec(g, g->set);
}
