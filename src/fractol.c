/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:27:57 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/27 18:25:06 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_thread(int thr, int step, t_data *data)
{
	if (thr)
	{
		if (step)
			error_config("Threads could not be joined.", data);
		else
			error_config("Threads could not be created.", data);
	}
}

void	t_render(t_data *data)
{
	t_tdata		tdata[N_THREADS];
	pthread_t	threads[N_THREADS];
	int			thr;
	int			i;

	i = -1;
	while (++i < N_THREADS)
	{
		tdata[i].id = i;
		tdata[i].data = data;
		if (data->g->set == JUL)
			thr = pthread_create(&threads[i], NULL,
					tjulia_loop, (void *)&tdata[i]);
		else if (data->g->set == BS)
			thr = pthread_create(&threads[i], NULL,
					tburning_ship_loop, (void *)&tdata[i]);
		else
			thr = pthread_create(&threads[i], NULL,
					tmandelbrot_loop, (void *)&tdata[i]);
		check_thread(thr, 0, data);
	}
	while (i)
	{
		thr = pthread_join(threads[--i], NULL);
		check_thread(thr, 1, data);
	}
}

void	render(t_data *data)
{
	t_config	*g;

	g = data->g;
	if (g->set == JUL)
		julia_loop(data);
	else if (g->set == BS)
		burning_ship_loop(data);
	else
		mandelbrot_loop(data);
}

void	fract_ol(t_data *data)
{
	t_config	*g;

	g = data->g;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, g->res, g->res, "fract-ol");
	data->img = mlx_new_image(data->mlx, g->res, g->res);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	//render(data);
	t_render(data);
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
			fract_ol(data);
		}
	}
	else
		error_type();
	return (0);
}
