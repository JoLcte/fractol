/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecomte <jlecomte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:29:15 by jlecomte          #+#    #+#             */
/*   Updated: 2021/07/22 23:34:13 by jlecomte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	colors_16(int *rgb)
{
	rgb[0] = 0x421E0F;
	rgb[1] = 0x19071A;
	rgb[2] = 0x09012F;
	rgb[3] = 0x040449;
	rgb[4] = 0x000764;
	rgb[5] = 0x0C2F8A;
	rgb[6] = 0x1852B1;
	rgb[7] = 0x397DD1;
	rgb[8] = 0x86B5E5;
	rgb[9] = 0xD3ECF8;
	rgb[10] = 0xF3E9BF;
	rgb[11] = 0xF8C95F;
	rgb[12] = 0xFFAA00;
	rgb[13] = 0xCC8000;
	rgb[14] = 0x995700;
	rgb[15] = 0x6A3403;
}

static void	colors_29(int *rgb)
{
	rgb[0] = 0x520016;
	rgb[1] = 0x870E37;
	rgb[2] = 0xB64B5D;
	rgb[3] = 0xDB8E84;
	rgb[4] = 0xEEC8a3;
	rgb[5] = 0xF1eFc9;
	rgb[6] = 0xE2EDE2;
	rgb[7] = 0xC0CFF0;
	rgb[8] = 0x9197F2;
	rgb[9] = 0x6154EE;
	rgb[10] = 0x2D15DA;
	rgb[11] = 0x000373;
	rgb[12] = 0x003a50;
	rgb[13] = 0x107D2C;
	rgb[14] = 0x39BC0E;
	rgb[15] = 0x6DE601;
	rgb[16] = 0x9AF500;
	rgb[17] = 0xE7AB00;
	rgb[18] = 0xFD6900;
	rgb[19] = 0xEE2815;
	rgb[20] = 0xB80064;
	rgb[21] = 0x89008D;
	rgb[22] = 0x4A22AB;
	rgb[23] = 0x265DCE;
	rgb[24] = 0x01A4E4;
	rgb[25] = 0x00F5F5;
	rgb[26] = 0x1BC3D5;
	rgb[27] = 0x438CB8;
	rgb[28] = 0x764196;
}

void	rgb_palette(t_config *g, int n)
{
	if (n == 1)
	{
		g->n_colors = 16;
		colors_16(g->rgb);
	}
	else if (n == 2)
	{
		g->n_colors = 29;
		colors_29(g->rgb);
	}
}
