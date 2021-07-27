/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:14:43 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/28 00:20:16 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_arg(const char *s)
{
	printf("\e[38;5;196mError:\n\e[m");
	printf("%s\n", s);
	exit(-1);
}

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

void	error_type(void)
{
	printf("\e[38;5;196mError:\e[m\n");
	printf("Type 'julia, 'mandelbrot' or 'burningship' for a fractal type.\n");
	exit(-1);
}

void	print_help(void)
{
	printf("\n   HELP MENU:\n");
	printf("   ---------\n");
	printf("   W or UP_ARROW = move up\n");
	printf("   A or LEFT_ARROW = move left\n");
	printf("   S or DOWN_ARROW = move down\n");
	printf("   D or RIGHT_ARROW = move right\n");
	printf("   SPACE to switch colors\n");
	printf("   I to increase real c component for Julia set\n");
	printf("   K to decrease real c component for Julia set\n");
	printf("   J to increase imaginary c component for Julia set\n");
	printf("   K to decrease imaginary c component for Julia set\n");
	printf("   X for Julia set with c(-0.51, 0.52)\n");
	printf("   Z for Julia set with c(0.285, 0.01)\n");
	printf("   B to zoom to an interesting Burning Ship\n");
	printf("   H to print this HELP MENU\n");
	printf("   ESC to exit the program\n");
	printf("   -------------------------------------------------\n");
}
