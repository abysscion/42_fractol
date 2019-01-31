/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:55:00 by emayert           #+#    #+#             */
/*   Updated: 2019/01/29 18:55:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_mlx(s_storage *box)
{
	box->mlx = mlx_init();
	box->win = mlx_new_window(box->mlx, WIN_W, WIN_H + 20, "Le Masterpiece");
	box->img = mlx_new_image(box->mlx, WIN_W, WIN_H);
	box->img_bar = mlx_new_image(box->mlx, WIN_W, 20);
	box->img_help = mlx_new_image(box->mlx, HELP_W, HELP_H);
	box->ptimg = mlx_get_data_addr(box->img,
									&box->bits_per_pixel,
									&box->size_line,
									&box->endian);
}

void	init_box(s_storage *box)
{
	box->help_toggled = -1;
	box->coloring = 1;
	box->img_help = 0x0;
	box->img_bar = 0x0;
	box->ftype = -1;
	box->color = COLOR_1;
	box->mlx = 0x0;
	box->win = 0x0;
	box->img = 0x0;
}

void	init_fractal(s_storage *box)
{
	box->zoom_count = 0.0f;
	if (box->ftype == 0)
		init_mandelbrot(box);
	else	if (box->ftype == 1)
				init_julia(box);
			else	if (box->ftype == 2)
					init_bship(box);
	split_fractal(box);
}
