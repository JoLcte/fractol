/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:27:57 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/18 18:44:48 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_arg("Memory could not be allocated.");
	if (ac == 2)
	{
		if (*av[1] != 'j' && *av[1] != 'm')
			error_arg("Type 'julia' or 'mandelbrot' to choose a fractal.");
		else
		{
			check_arg(&av[1]);
			render(av[1], data);
		}
		//gradient(g->rgb, ...);
	}
	else if (ac == 3)
	{
		check_arg(&av[1]);
		//gradient(g->rgb, av[2]);
		render(av[1], data);
		//parse rgb colors av[2]
	}
	else
		printf("valid arguments = ... to be continued\n");
	return (0);
}
