/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:51:38 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/23 00:33:05 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len +
			x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int exit_and_free(t_data *data)
{
	mlx_do_key_autorepeaton(data->mlx);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	if (data)
		free(data);
	exit(1);
	return (1);
}

static void change_burning_ship(t_data *data)
{
	t_config *g;

	g = data->g;
	g->canva_s = 0.1;
	g->factor = g->canva_s / g->res;
	g->ul[X] = -1.8;
	g->ul[Y] = 0.09;
	g->center[X] = g->ul[X] + g->canva_s / 2;
	g->center[Y] = g->ul[Y] - g->canva_s / 2;
	burning_ship_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);

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

int get_mouse_scroll(int key, int x, int y, t_data *data)
{
	if (key == 5)
		zoom_in(x, y, data);
	else if (key == 4)
		zoom_out(x, y, data);
	return (1);
}

int get_keypress(int key, t_data *data)
{
	if (key == 65307)
		return (exit_and_free(data));
	else if (key == 104)
		print_help();
	else if (key == 65362 || key == 119)
		move_up(data);
	else if (key == 65364 || key == 115)
		move_down(data);
	else if (key == 65361 || key == 97)
		move_left(data);
	else if (key == 65363 || key == 100)
		move_right(data);
	else if (key == 32)
		switch_palette(data);
	else if ((key == 105 || key == 106 || key == 107 || key == 108
				|| key == 120 || key == 122) && data->g->set == 1)
		change_julia(data, key);
	else if (key == 98 && data->g->set == -1)
		change_burning_ship(data);
	return (1);
}
