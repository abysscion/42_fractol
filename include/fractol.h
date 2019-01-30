/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 06:37:00 by emayert           #+#    #+#             */
/*   Updated: 2019/01/28 06:37:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "keys.h"
# include <math.h>
# include <pthread.h>
# include "../lib/libmlx/mlx.h"
# include "../lib/libft/libft.h"

# ifdef __linux__
#  define WIN_W			640
#  define WIN_H 		480
#  define SEGS_HEIGHT	5
#  define THREADS_NUM	96
# elif
#  define WIN_W 		1440
#  define WIN_H 		810
#  define SEGS_HEIGHT 	25
#  define THREADS_NUM	32
# endif
# define ZOOM_STEP		1.1
# define ITER_STEP		25
# define MSG_USAGE	"\
usage:			\e[1m./fractol\e[0m \e[33mpattern_name\e[0m\n\
available patterns:	[\e[33mmandelbrot\e[0m | \e[33mjulia\e[0m \
| \e[33mdunnoyet\e[0m]"

typedef	struct	t_storage
{
	double	ofsx;
	double	ofsy;
	double	zoom;
	double	tmp;
	double	zi;
	double	zr;
	double	ci;
	double	cr;
	double	x;
	double	y;
	void	*mlx;
	void	*win;
	void	*img;
	void	*ptimg;
	int		itnum;
	int		color;
	int		ftype;
	int		y_cap;
	int		i;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				s_storage;

void			ppx_on_img(int x, int y, int color, s_storage *box);
void			zoom(char sign, int x, int y, s_storage *b);
void			init_mandelbrot(s_storage *box);
void			split_mandelbrot(s_storage *box);
void			split_fractal(s_storage *box);
void			init_fractal(s_storage *box);
void			init_mlx(s_storage *box);
void			init_box(s_storage *box);
void			free_box(s_storage *box);
int				mouse_hook(int key, int x, int y, s_storage *box);
int				key_hook(int key, s_storage *box);

#endif