/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:27:57 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/24 10:48:19 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_data *data)
{
	t_config	*g;

	g = data->g;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, g->res, g->res, "fract-ol");
	data->img = mlx_new_image(data->mlx, g->res, g->res);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	if (g->set > 0)
		julia_loop(data);
	else if (g->set < 0)
		burning_ship_loop(data);
	else
		mandelbrot_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_do_key_autorepeaton(data->mlx);
	mlx_hook(data->win, 2, 1L << 0, get_keypress, data);
	mlx_hook(data->win, 4, 4L << 0, get_mouse_scroll, data);
	mlx_hook(data->win, 33, 1L << 17, exit_and_free, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data		*data;
	t_config	g;

	if (ac == 2)
	{
		if (*av[1] != 'j' && *av[1] != 'm' && *av[1] != 'b')
			error_type();
		else
		{
			init_g(&g);
			parse(&g, av[1]);
			data = (t_data *)malloc(sizeof(t_data));
			if (!data)
				error_arg("Memory could not be allocated.");
			data->g = &g;
			render(data);
		}
	}
	else
		error_type();
	return (0);
}
