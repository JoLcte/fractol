/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:28:26 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/13 22:29:01 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define X 0
# define Y 1
# define R 0
# define G 1
# define B 2

/*
 ** DATA
 */

typedef struct s_config
{
	float res[2];
	float rgb[3];
} t_config;

typedef struct s_data
{
	t_config *g;
	void *mlx;
	void *img;
	char *addr;
	void *win;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

void render(const char *s, t_data *data);

#endif
