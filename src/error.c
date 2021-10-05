/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:14:43 by jlecomte          #+#    #+#             */
/*   Updated: 2021/10/05 18:31:27 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_colors(const char *s, t_config *g)
{
	int	i;

	printf("\e[38;5;196mError:\e[m\n");
	printf("%s\n", s);
	i = 0;
	if (g->gradient->palette[i])
		while (i < N_PALETTES)
			free(g->gradient->palette[i++]);
	i = 0;
	if (g->rgb[i])
		while (i < N_PALETTES)
			free(g->rgb[i++]);
	if (g->gradient->indexes)
		free(g->gradient->indexes);
	if (g->gradient->palette)
		free(g->gradient->palette);
	if (g->gradient)
		free(g->gradient);
	if (g->rgb)
		free(g->rgb);
	exit(-1);
}

void	error_config(const char *s, t_data *data)
{
	t_config	*g;
	int			i;

	g = data->g;
	printf("\e[38;5;196mError:\e[m\n");
	printf("%s\n", s);
	i = 0;
	if (g->gradient->palette[i])
		while (i < N_PALETTES)
			free(g->gradient->palette[i++]);
	i = 0;
	if (g->rgb[i])
		while (i < N_PALETTES)
			free(g->rgb[i++]);
	if (g->gradient->palette)
		free(g->gradient->palette);
	if (g->gradient->indexes)
		free(g->gradient->indexes);
	if (g->gradient)
		free(g->gradient);
	if (g->rgb)
		free(g->rgb);
	if (data)
		free(data);
	exit(-1);
}

void	error_str(const char *s)
{
	printf("\e[38;5;196mError:\e[m\n");
	printf("%s\n", s);
	exit(-1);
}

void	error_arg(void)
{
	printf("\e[38;5;196mError:\e[m\n");
	printf("Fractale types: 'julia', 'mandelbrot' or 'burning_ship'\n");
	printf("ex: ./fractol julia\n");
	exit(-1);
}
