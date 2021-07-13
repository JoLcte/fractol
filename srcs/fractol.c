/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:27:57 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/13 22:32:53 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void error_arg(char *s)
{
	printf("\e[38;5;196mError:\n\e[m");
	printf("%s\n", s);
	exit(0);
}

static void check_arg(char **str)
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

int main(int ac, char **av)
{
	t_data *data;

	data = 0;
	if (ac >= 2)
	{
		if (*av[1] != 'j' && *av[1] != 'm')
			error_arg("Type 'julia' or 'mandelbrot' to choose a fractal.");
		else
		{
			check_arg(&av[1]);
			render(av[1], data);
		}
	}
	return (0);
}
