/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:50:19 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/23 00:29:37 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int check_arg(const char *s1, const char *s2, int n)
{
		while (n-- && *s2)
		{
			if (!*s1 ||  *s1++ != *s2++)
				return (1);
		}
		if (*s1)
			return (1);
		return (0);
}

void	init_g(t_config *g)
{
	g->set = 1;
	g->res = 1000;
	g->canva_s = 3.0;
	g->ul[X] = - g->canva_s / 2.0;
	g->ul[Y] = g->canva_s / 2.0;
	g->center[X] = 0.0;
	g->center[Y] = 0.0;
	g->factor = g->canva_s / g->res;
	rgb_palette(g, 1);
}

void parse(t_config *g, char *s)
{
	const char *s1 = "julia";
	const char *s2 = "mandelbrot";
	const char *s3 = "burning_ship";

	if (*s == 'j')
	{
		if (check_arg(s, s1, 5))
				error_arg("'julia' is misspelled.");
		g->c[R] = 0.285;
		g->c[I] = 0.01;
	}
	else if (*s == 'm')
	{
		if (check_arg(s, s2, 10))
				error_arg("'mandelbrot' is misspelled.");
		g->set = 0;
		g->center[X] -= 0.55;
		g->ul[X] -= 0.55;
	}
	else
	{
		if (check_arg(s, s3, 12))
			error_arg("'burning_ship' is misspelled.");
		g->set = -1;
	}
}
