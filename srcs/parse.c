/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:50:19 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/18 21:33:08 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void check_arg(char **str)
{
	int n1;
	int n2;
	const char *s1 = "julia";
	const char *s2 = "mandelbrot";
	char *s = *str;

	n1 = 5;
	n2 = 10;
	if (*s == 'j')
	{
		while (n1-- > 0 && *s1)
			if (!*s || *s++ != *s1++)
				error_arg("'julia' is misspelled.");
		if (*s && *s != ' ')
			error_arg("'julia' is misspelled.");
	}
	else
	{
		while (n2-- > 0 && *s2)
			if (!*s || *s++ !=* s2++)
				error_arg("'mandelbrot' is misspelled.");
		if (*s && *s != ' ')
			error_arg("'mandelbrot' is misspelled.");
	}
	*str = s;
}

int ft_atoi(const char **s)
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

double	get_double(const char **s)
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

void up_config(const char *s, t_data *data)
{
	int i;

	i = 0;
	while (*s == ' ')
		++s;
	if ((unsigned)*s - '0' < 10 || *s == '-')
		data->g->c[R] = get_double(&s);
	else
		error_config("C's real coordinate must be between -1 and 1.", data);
	if (*s == ',')
		++s;
	if ((unsigned)*s - '0' < 10 || *s == '-')
		data->g->c[I] = get_double(&s);
	else
		error_config("C's imaginary coordinate must be between -1 and 1.", data);

	data->g->rgb[0] = rgb_to_color(66, 30, 15);
	data->g->rgb[1] = rgb_to_color(25, 7, 26);
	data->g->rgb[2] = rgb_to_color(9, 1, 47);
	data->g->rgb[3] = rgb_to_color(4, 4, 73);
	data->g->rgb[4] = rgb_to_color(0, 7, 100);
	data->g->rgb[5] = rgb_to_color(12, 47, 138);
	data->g->rgb[6] = rgb_to_color(24, 82, 177);
	data->g->rgb[7] = rgb_to_color(57, 125, 209);
	data->g->rgb[8] = rgb_to_color(134, 181, 229);
	data->g->rgb[9] = rgb_to_color(211, 236, 248);
	data->g->rgb[10] = rgb_to_color(243, 233, 191);
	data->g->rgb[11] = rgb_to_color(248, 201, 95);
	data->g->rgb[12] = rgb_to_color(255, 170, 0);
	data->g->rgb[13] = rgb_to_color(204, 128, 0);
	data->g->rgb[14] = rgb_to_color(153, 87, 0);
	data->g->rgb[15] = rgb_to_color(106, 52, 3);

	//color_parsing;
}
