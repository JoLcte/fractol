/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:27:57 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/19 21:47:22 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_data *data;
	t_config g;

	if (ac == 2)
	{
		if (*av[1] != 'j' && *av[1] != 'm')
			error_arg("Type 'julia' or 'mandelbrot' to choose a fractal.");
		else
		{
			check_arg(&g, &av[1]);
			data = (t_data *)malloc(sizeof(t_data));
			if (!data)
				error_arg("Memory could not be allocated.");
			data->g = &g;
			render(data);
		}
		//gradient(g->rgb, ...);
	}
	else
		printf("valid arguments = ... to be continued\n");
	return (0);
}
