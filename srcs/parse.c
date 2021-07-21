/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:50:19 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/21 23:49:42 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void check_arg(t_config *g, char **str)
{
	int n1;
	int n2;
	const char *s1 = "julia";
	const char *s2 = "mandelbrot";
	char *s = *str;

	n1 = 5;
	n2 = 10;
	g->res = 1200;
	g->canva_s = 3.0;
	g->ul[X] = - g->canva_s / 2.0;
	g->ul[Y] = g->canva_s / 2.0;
	g->factor = g->canva_s / (g->res - 1);
	if (*s == 'j')
	{
		while (n1-- > 0 && *s1)
			if (!*s || *s++ != *s1++)
				error_arg("'julia' is misspelled.");
		if (*s && *s != ' ')
			error_arg("'julia' is misspelled.");
		g->set = 1.0;
		if (!*s)
		{
			g->c[R] = 0.285;
			g->c[I] = 0.01;
		}
		if (*s)
		{
			while (*s == ' ')
				++s;
			if ((unsigned)*s - '0' < 10 || *s == '-')
				g->c[R] = get_double(&s);
			else
				error_arg("C's real coordinate must be between -1 and 1.");
			if (*s == ',')
				++s;
			if ((unsigned)*s - '0' < 10 || *s == '-')
				g->c[I] = get_double(&s);
			else
				error_arg("C's imaginary coordinate must be between -1 and 1.");
		}
	}
	else
	{
		while (n2-- > 0 && *s2)
			if (!*s || *s++ !=* s2++)
				error_arg("'mandelbrot' is misspelled.");
		if (*s && *s != ' ')
			error_arg("'mandelbrot' is misspelled.");
		g->set = 0.0;
		g->ul[X] -= 0.55;
	}
	g->rgb[0] = rgb_to_color(66, 30, 15);
	g->rgb[1] = rgb_to_color(25, 7, 26);
	g->rgb[2] = rgb_to_color(9, 1, 47);
	g->rgb[3] = rgb_to_color(4, 4, 73);
	g->rgb[4] = rgb_to_color(0, 7, 100);
	g->rgb[5] = rgb_to_color(12, 47, 138);
	g->rgb[6] = rgb_to_color(24, 82, 177);
	g->rgb[7] = rgb_to_color(57, 125, 209);
	g->rgb[8] = rgb_to_color(134, 181, 229);
	g->rgb[9] = rgb_to_color(211, 236, 248);
	g->rgb[10] = rgb_to_color(243, 233, 191);
	g->rgb[11] = rgb_to_color(248, 201, 95);
	g->rgb[12] = rgb_to_color(255, 170, 0);
	g->rgb[13] = rgb_to_color(204, 128, 0);
	g->rgb[14] = rgb_to_color(153, 87, 0);
	g->rgb[15] = rgb_to_color(106, 52, 3);
	*str = s;
}

int ft_atoi(char **s)
{
	unsigned int tmp;
	int n;

	tmp = (unsigned)**s - '0';
	n = 0;
	while (tmp < 10)
	{
		n = n * 10 + tmp;
		++(*s);
		tmp = (unsigned)**s - '0';
	}
	return (n);
}

double	get_double(char **s)
{
	double tmp;
	double n;
	int i;
	int sign;

	n = 0;
	i = 10;
	sign = 1;
	if (**s == '-')
	{
		sign = -1;
		++(*s);
	}
	n = ft_atoi(s);
	if (**s == '.')
	{
		tmp = (unsigned)*(++*s) - '0';
		while (tmp < 10)
		{
			n += tmp / i;
			i *= 10;
			tmp = (unsigned)*(++(*s)) - '0';
		}
	}
	return (n * sign);
}
