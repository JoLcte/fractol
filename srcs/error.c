/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:14:43 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/14 16:21:50 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_arg(const char *s)
{
	printf("\e[38;5;196mError:\n\e[m");
	printf("%s\n", s);
	exit(0);
}

void error_config(const char *s, t_config *g)
{
	printf("\e[38;5;196mError:\e[m\n");
	printf("%s\n", s);
	if (g)
		free(g);
	exit(0);
}
