/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:18:07 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/14 17:56:02 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_magic(t_config *g, float i, float j)
{
	int color;
	int n_max = 1000;
	float z[2];

	z[X] = p[X];
	z[Y] = p[Y];
	
	// redefinir coordonees du pixel selon ref 3-3
	float a = pow(p[X], 2) - pow(p[Y], 2);

	while (a < 4 || n < n_max)
	{
	}
	
	ComplexNumber newz = new ComplexNumber(2.0*(X-WIDTH/2)/(WIDTH/2), 1.33*(Y-HEIGHT/2)/(HEIGHT/2) );
            int i;
            for(i=0;i<max_iter; i++)
            {
                oldz = newz;
                newz = newz.square();
                newz.add(constant);
                if(newz.mod() > 2)
                    break;
            }
        }
		color = g->rgb[n % 64];
    }
	return (color);
	
}

void	render(const char *s, t_data *data)
{
	t_config *g;
	int color;
	float bg[3];
	int p[2];
	g = 0;

	data = malloc(sizeof(t_data));
	if (!data)
		error_config("Memory could not be allocated.", g);
	g = malloc(sizeof(t_config));
	if (!g)
		error_config("Memory could not be allocated.", g);
	data->g = g;
	up_config(s, g);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, g->res[X], g->res[Y], "fractol");
	data->img = mlx_new_image(data->mlx, g->res[X], g->res[Y]);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	p[Y] = 0;
	while (p[Y])
	{
		p[X] = 0;
		while (p[X] < g->res[X])
		{
			color = julia_magic(g, (float)p[X], (float)p[Y]);
			/*bg[R] = g->rgb[R] * (float)x / (g->res[X] - 1);
			bg[G] = g->rgb[G] * (float)y / (g->res[Y] - 1);
			bg[B] = g->rgb[B] * 0.25;*/
			my_mlx_pixel_put(data, x, y, color);
			p[X];
		}
		p[Y];
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 2, 1L<<0, get_keypress, data);
	mlx_hook(data->win, 33, 1L<<17, exit_and_free, data);
	mlx_loop(data->mlx);
}
