/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:05:00 by emayert           #+#    #+#             */
/*   Updated: 2019/01/29 19:05:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	split_fractal(s_storage *box)
{
	if (box->itnum < 0)
		box->itnum = 0;
	if (box->ftype == 0)
		split_mandelbrot(box);
	else	if (box->ftype == 1)
				split_julia(box);
			else	if (box->ftype == 2)
						printf("dunnoyet split\n");
	box->help_toggled = -1;
	show_info(box);
	
}

void	ppx_on_img(int x, int y, int color, s_storage *box)
{
	if (box->x < WIN_W && box->y < WIN_H)
	{
		color = mlx_get_color_value(box->mlx, color);
		ft_memcpy(box->ptimg + 4 * WIN_W * y + x * 4, &color, sizeof(int));
	}
}
