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

# include "../lib/libft/libft.h"
# include "../lib/libmlx/mlx.h"
# include "keys.h"
# include <math.h>
# include <pthread.h>

# ifdef __linux__
#  define WIN_W			640
#  define WIN_H 		480
#  define HELP_W		180
#  define HELP_H		100
#  define SEGS_HEIGHT		5
#  define THREADS_NUM		96
# else
#  define WIN_W 		1440
#  define WIN_H 		810
#  define HELP_W		300
#  define HELP_H		170
#  define SEGS_HEIGHT		90
#  define THREADS_NUM		9
# endif

# define ZOOM_STEP		1.2
# define ITER_STEP		25
# define COLOR_1		0x000202
# define COLOR_2		0x020002
# define COLOR_3		0x020200
# define COLOR_4		0x123456

typedef	struct	s_storage
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
	float	zoom_count;
	void	*img_help;
	void	*img_bar;
	void	*ptimg;
	void	*mlx;
	void	*win;
	void	*img;
	int		bits_per_pixel;
	int		help_toggled;
	int		size_line;
	int		coloring;
	int		mjulia;
	int		endian;
	int		itnum;
	int		color;
	int		ftype;
	int		y_cap;
	int		i;
}				t_storage;

void			ppx_on_img(int x, int y, int color, t_storage *box);
void			zoom(char sign, int x, int y, t_storage *b);
void			change_color(int key, t_storage *box);
void			split_mandelbrot(t_storage *box);
void			init_mandelbrot(t_storage *box);
void			split_fractal(t_storage *box);
void			init_fractal(t_storage *box);
void			split_bship(t_storage *box);
void			split_julia(t_storage *box);
void			init_bship(t_storage *box);
void			init_julia(t_storage *box);
void			show_help(t_storage *b);
void			show_info(t_storage *b);
void			init_mlx(t_storage *box);
void			init_box(t_storage *box);
void			free_box(t_storage *box);
int				mouse_hook(int key, int x, int y, t_storage *box);
int				mouse_julia(int x, int y, t_storage *box);
int				key_hook(int key, t_storage *box);

#endif
