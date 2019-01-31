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

#ifdef __linux__
# define ERR_Y 15
# define MOFSY 15
# define ERR_X 120
#else
# define ERR_Y 0
# define MOFSY 20
# define ERR_X 180
#endif


void			zoom(char sign, int x, int y, s_storage *b)
{
	if (sign == '-')
	{
		b->ofsx = (x * b->zoom + b->ofsx) - (x * (b->zoom * ZOOM_STEP));
		b->ofsy = (y * b->zoom + b->ofsy) - (y * (b->zoom * ZOOM_STEP));
		b->zoom *= ZOOM_STEP;
		b->zoom_count -= 0.25f;
	}
	else
	{
		b->ofsx = (x * b->zoom + b->ofsx) - (x * (b->zoom / ZOOM_STEP));
		b->ofsy = (y * b->zoom + b->ofsy) - (y * (b->zoom / ZOOM_STEP));
		b->zoom /= ZOOM_STEP;
		b->zoom_count += 0.25f;
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
  char *strz;
  char *strzn;
  char *stri;
  char *strin;
  int ofsy;

  strzn = ft_itoa(b->zoom_count);
  strin = ft_itoa(b->itnum);
  strz = ft_strjoin("zoom: x", strzn);
  stri = ft_strjoin("iterations count: ", strin);
  ofsy = WIN_H + ERR_Y;
  mlx_put_image_to_window(b->mlx, b->win, b->img_bar, 0, WIN_H);
  mlx_string_put(b->mlx, b->win, 5, ofsy, 0x00aaee, stri);
  mlx_string_put(b->mlx, b->win, WIN_W * 0.5 - 80, ofsy, 0x00aaee, strz);
  mlx_string_put(b->mlx, b->win, WIN_W - ERR_X, ofsy, 0x00aaee, "[H] - toggle help");
  free(strz);
  free(stri);
  free(strzn);
  free(strin);







  /*
	char	*z;
	char	*i;
	int		ofsy;
	
	i = ft_itoa(b->itnum);
	z = ft_itoa(b->zoom_count);
	ofsy = WIN_H + ERR_Y;
	mlx_put_image_to_window(b->mlx, b->win, b->img_bar, 0, WIN_H);
	mlx_string_put(b->mlx, b->win, 5, ofsy, 0x00aaee, "zoom: x");
	mlx_string_put(b->mlx, b->win, 48, ofsy, 0x00aaee, z);
	mlx_string_put(b->mlx, b->win, WIN_W * 0.5 - 80, ofsy, 0x00aaee,
					"iterations number: x");
	mlx_string_put(b->mlx, b->win, WIN_W * 0.5 + 40, ofsy, 0x00aaee, i);
	mlx_string_put(b->mlx, b->win, WIN_W - 120, ofsy, 0x00aaee,
					"[H] - toggle help");
	free(z);
	free(i);
  */
}

static	void	put_text(int x, int y, s_storage *b)
{
	mlx_string_put(b->mlx, b->win, x + 5, y + MOFSY, 0xB56102,
					"[MWheel] - Zoom");
	mlx_string_put(b->mlx, b->win, x + 5, y + MOFSY * 2, 0xB56102,
					"[+/-]    - Iterations number");
	mlx_string_put(b->mlx, b->win, x + 5, y + MOFSY * 3, 0xB56102,
					"[1-4]    - Color switching");
	mlx_string_put(b->mlx, b->win, x + 5, y + MOFSY * 4, 0xB56102,
					"[R]      - Reset image");
	mlx_string_put(b->mlx, b->win, x + 5, y + MOFSY * 5, 0xB56102,
					"[ESC]    - Quit");
	mlx_string_put(b->mlx, b->win, x + 5, y + MOFSY * 6, 0xB56102,
					"[J]      - Toogle julia mouse");
}

void			show_help(s_storage *b)
{
	int	ofsx;
	int	ofsy;
	int x;
	int y;

	if (b->help_toggled == 1)
	{
		ofsx = WIN_W / 2 - HELP_W / 2;
		ofsy = WIN_H / 2 - HELP_H / 2;
		mlx_put_image_to_window(b->mlx, b->win, b->img_help, ofsx, ofsy);
		x = -1;
		while (++x < HELP_W)
		{
			y = -1;
			while (++y < HELP_H)
				mlx_pixel_put(b->mlx, b->win, ofsx + x, ofsy + y, 0x003D5B);
		}
		put_text(ofsx, ofsy, b);
	}
	else
		split_fractal(b);
}
