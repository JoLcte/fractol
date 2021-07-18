/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:18:07 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/18 18:44:24 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_magic(t_config *g, float a, float b)
{
	int color;
	int n_max = 1000;
	int n;
	float tmp;

	n = 0;
	n_max = 1000;

	while (pow(a, 2) + pow(b, 2) <= 4 || n++ <= n_max)
	{
		tmp = pow(a, 2) - pow(b, 2) + g->c[R];
		b = 2 * a * b + g->c[I];
		a = tmp;
	}
	if (n != n_max)
		color = n * 16777215 / n_max;
		//color = g->rgb[n % 64];
	else
		color = 0;
	return (color);
}

void	render(const char *s, t_data *data)
{
	t_config *g;
	int color;
	float p[2];
	int i;
	int j;
	g = 0;
	const float factor_x = 3.0 * (16 / 9) / 1919;
	const float factor_y = 3.0 / 1079;
	float ul[2];

	g = (t_config *)malloc(sizeof(t_config));
	if (!g)
		error_config("Memory could not be allocated.", data);
	data->g = g;
	if (*s)
		up_config(s, data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "fractol");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	j = 0;
	ul[X] = -1.5;
	ul[Y] = 1.5;
	while (j < 1079)
	{
		i = 0;
		while (i < 1919)
		{
			p[X] = ul[X] + (float)i * factor_x;
			p[Y] = ul[Y] - (float)j * factor_y;
			color = julia_magic(g, p[X], p[Y]);
			my_mlx_pixel_put(data, i, j, color);
			++i;
		}
		--j;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 2, 1L<<0, get_keypress, data);
	mlx_hook(data->win, 33, 1L<<17, exit_and_free, data);
	mlx_loop(data->mlx);
}
