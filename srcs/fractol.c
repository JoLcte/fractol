/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:27:57 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/14 16:24:49 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_data *data;

	data = 0;
	if (ac >= 2)
	{
		if (*av[1] != 'j' && *av[1] != 'm')
			error_arg("Type 'julia' or 'mandelbrot' to choose a fractal.");
		else
		{
			check_arg(&av[1]);
			render(av[1], data);
		}
	}
	return (0);
}
