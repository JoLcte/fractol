/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:50:19 by jlecomte          #+#    #+#             */
/*   Updated: 2021/10/05 16:20:51 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (1);
	while (n-- && *s1)
	{
		if (!*s2 || *s1 != *s2)
			return (1);
		++s1;
		++s2;
	}
	if (*s2)
		return (1);
	return (0);
}

void	parse(t_config *g, char *s)
{
	if (!ft_strncmp("julia", s, 5))
		g->set = JUL;
	else if (!ft_strncmp("mandelbrot", s, 10))
		g->set = MDL;
	else if (!ft_strncmp("burning_ship", s, 12))
		g->set = BS;
	else
		error_arg();
}
