/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:52:31 by jlecomte          #+#    #+#             */
/*   Updated: 2021/10/05 18:05:51 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_julia_c(t_config *g)
{
	printf("Julia: c[R] = %.4f, c[I] = %.4f\n", g->c[R], g->c[I]);
}

static void	print_keys(t_config *g)
{
	printf("\n   HELP MENU:\n");
	printf("   ---------\n");
	printf("   W or UP_ARROW = move up\n");
	printf("   A or LEFT_ARROW = move left\n");
	printf("   S or DOWN_ARROW = move down\n");
	printf("   D or RIGHT_ARROW = move right\n");
	printf("   + or N to zoom in\n");
	printf("   - to M zoom out\n");
	printf("   SPACE to switch colors\n");
	printf("   C to make colors shift\n");
	printf("   I to increase real c component for Julia set\n");
	printf("   K to decrease real c component for Julia set\n");
	printf("   J to increase imaginary c component for Julia set\n");
	printf("   L to decrease imaginary c component for Julia set\n");
	printf("   P to print c constant coordinates for Julia set\n");
	printf("   X for Julia set with c(-0.7850, 0.1520)\n");
	printf("   Z for Julia set with c(%.4f, %.4f)\n", g->c[R], g->c[I]);
	printf("   B to zoom to an interesting Burning Ship\n");
	printf("   H to print this HELP MENU\n");
	printf("   ESC to exit the program\n");
	printf("   -------------------------------------------------\n");
}

void	print_help(t_config *g, int key)
{
	if (key == 112 && g->set == JUL)
		print_julia_c(g);
	else if (key == 104)
		print_keys(g);
}
