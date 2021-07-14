/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:50:19 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/14 17:48:54 by jlecomte         ###   ########.fr       */
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

void up_config(const char *s, t_config *g)
{
	if (*s)
	{
		while (*s == ' ')
			++s;
		if ((unsigned char)*s - '0'  < 10)
			g->c[R] = ft_atoi(&s);
		else
			error_config("C real coordinate is not valid.", g);
		while (*s == ' ')
			++s;
		if ((unsigned char)*s - '0'  < 10)
			g->c[I] = ft_atoi(&s);
		else
			error_config("C imaginary coordinate is not valid.", g);
		while (*s == ' ')
			++s;
		//if (*s)
		//color gestion g->rgb = ...;
	}
}
