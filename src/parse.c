/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:50:19 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/27 14:54:38 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_arg(const char *s1, const char *s2, int n)
{
	while (n-- && *s2)
	{
		if (!*s1 || *s1++ != *s2++)
			return (1);
	}
	if (*s1)
		return (1);
	return (0);
}

void	parse(t_config *g, char *s)
{
	const char	*s1 = "julia";
	const char	*s2 = "mandelbrot";
	const char	*s3 = "burning_ship";

	if (*s == 'j')
	{
		if (check_arg(s, s1, 5))
			error_arg("'julia' is misspelled.");
		g->set = JUL;
		init_spec(g, g->set);
	}
	else if (*s == 'm')
	{
		if (check_arg(s, s2, 10))
			error_arg("'mandelbrot' is misspelled.");
		g->set = MDL;
		init_spec(g, g->set);
	}
	else
	{
		if (check_arg(s, s3, 12))
			error_arg("'burning_ship' is misspelled.");
		g->set = BS;
		init_spec(g, g->set);
	}
}
