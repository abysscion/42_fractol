/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supply.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:20:00 by emayert           #+#    #+#             */
/*   Updated: 2019/01/29 09:20:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void			zoom(char sign, int x, int y, s_storage *b)
{
	if (sign == '+')
	{
		b->ofsx = (x / b->zoom + b->ofsx) - (x / (b->zoom * ZOOM_STEP));
		b->ofsy = (y / b->zoom + b->ofsy) - (y / (b->zoom * ZOOM_STEP));
		b->zoom *= ZOOM_STEP;
	}
	else
	{
		b->ofsx = (x / b->zoom + b->ofsx) - (x / (b->zoom / ZOOM_STEP));
		b->ofsy = (y / b->zoom + b->ofsy) - (y / (b->zoom / ZOOM_STEP));
		b->zoom /= ZOOM_STEP;
	}	
}

void			change_color(int key, s_storage *box)
{
	if (key == K_1)
		box->coloring = 0;
	else
	{
		box->coloring = 1;
		if (key == K_2)
				box->color = COLOR_1;
		else	if (key == K_3)
					box->color = COLOR_2;
				else	if (key == K_4)
							box->color = COLOR_3;
						else	if (key == K_5)
								box->color = COLOR_4;
	}	
}

void			show_info(s_storage *b)
{
	char	*z;
	char	*i;
	int		ofsy;
	int		zl;
	
	z = ft_itoa(b->zoom);
	i = ft_itoa(b->itnum);
	ofsy = WIN_H + 15;
	zl = 1;
	while (b->zoom / ft_power(10, zl) > 9)
		++zl;
	mlx_put_image_to_window(b->mlx, b->win, b->img_bar, 0, WIN_H);
	mlx_string_put(b->mlx, b->win, 5, ofsy, 0x00aaee, "zoom: x");
	mlx_string_put(b->mlx, b->win, 48, ofsy, 0x00aaee, z);
	mlx_string_put(b->mlx, b->win, 48 + zl * 11, ofsy, 0x00aaee,
					"iterations number: x");
	mlx_string_put(b->mlx, b->win, 48 + zl * 11 + 120, ofsy, 0x00aaee, i);
	mlx_string_put(b->mlx, b->win, WIN_W - 120, ofsy, 0x00aaee,
					"[H] - toggle help");
	free(z);
	free(i);
}

static	void	put_text(int x, int y, s_storage *b)
{
	mlx_string_put(b->mlx, b->win, x + 5, y + 15, 0xB56102,
					"[MWheel] - Zoom");
	mlx_string_put(b->mlx, b->win, x + 5, y + 30, 0xB56102,
					"[+/-]    - Iterations number");
	mlx_string_put(b->mlx, b->win, x + 5, y + 45, 0xB56102,
					"[1-4]    - Color switching");
	mlx_string_put(b->mlx, b->win, x + 5, y + 60, 0xB56102,
					"[R]      - Reset image");
	mlx_string_put(b->mlx, b->win, x + 5, y + 75, 0xB56102,
					"[ESC]    - Quit");
}

void			show_help(s_storage *b)
{
	int	ofsx;
	int	ofsy;
	int x;
	int y;

	if (b->help_toggled == 1)
	{
		ofsx = WIN_W / 2 - 90;
		ofsy = WIN_H / 2 - 75;
		mlx_put_image_to_window(b->mlx, b->win, b->img_help, ofsx, ofsy);
		x = -1;
		while (++x < 180)
		{
			y = -1;
			while (++y < 150)
				mlx_pixel_put(b->mlx, b->win, ofsx + x, ofsy + y, 0x003D5B);
		}
		put_text(ofsx, ofsy, b);
	}
	else
		split_fractal(b);
}
