/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:51:38 by jlecomte          #+#    #+#             */
/*   Updated: 2021/10/05 15:45:19 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len
			+ x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	destroy_mlx(t_data *data)
{
	mlx_do_key_autorepeaton(data->mlx);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
}

int	exit_and_free(t_data *data)
{
	int			i;

	destroy_mlx(data);
	if (data->mlx)
		free(data->mlx);
	if (data->g->gradient->indexes)
		free(data->g->gradient->indexes);
	i = N_PALETTES;
	while (--i >= 0)
		free(data->g->gradient->palette[i]);
	i = N_PALETTES;
	while (--i >= 0)
		free(data->g->rgb[i]);
	if (data->g->gradient->palette)
		free(data->g->gradient->palette);
	if (data->g->rgb)
		free(data->g->rgb);
	if (data->g->gradient)
		free(data->g->gradient);
	if (data)
		free(data);
	exit(1);
	return (1);
}

int	get_mouse_scroll(int key, int x, int y, t_data *data)
{
	if (key == 5)
		zoom_in(x, y, data);
	else if (key == 4)
		zoom_out(x, y, data);
	return (1);
}

int	get_keypress(int key, t_data *data)
{
	t_config	*g;

	g = data->g;
	if (key == 65307)
		return (exit_and_free(data));
	if (key == 99)
		color_shift(data);
	else if (key == 104 || key == 112)
		print_help(g, key);
	else if ((key >= 65361 && key <= 65364) || key == 119 || key == 97
		|| key == 100 || key == 115)
		move_all(key, data);
	else if (key == 61)
		move_in(data);
	else if (key == 45)
		move_out(data);
	else if (key == 32)
		change_palette(data);
	else if ((key == 105 || key == 106 || key == 107 || key == 108
			|| key == 120 || key == 122) && g->set == JUL)
		change_julia(data, key);
	else if (key == 98 && g->set == BS)
		change_burning_ship(data);
	return (1);
}
