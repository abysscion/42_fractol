/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 00:45:00 by emayert           #+#    #+#             */
/*   Updated: 2019/01/31 00:45:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

#ifdef __linux__
# define ZOOM_MULTI 2.1
# define OFSX_MULTI 1.525
# define OFSY_MULTI 1.15
#else
# define ZOOM_MULTI 4.5
# define OFSX_MULTI 1.6
# define OFSY_MULTI 0.9
#endif

int				mouse_julia(int x, int y, t_storage *box)
{
	if (box->ftype == 1 && box->mjulia)
	{
		box->cr = x * 2;
		box->ci = y * 2 - 800;
		split_fractal(box);
	}
	return (0);
}

void			init_julia(t_storage *box)
{
	box->itnum = ITER_STEP;
	box->zoom = 1.0 / (100.0 * ZOOM_MULTI);
	box->ofsx = -1.0 * OFSX_MULTI;
	box->ofsy = -1.0 * OFSY_MULTI;
	box->cr = 0.285;
	box->ci = 0.01;
	box->mjulia = 1;
}

static	void	draw_julia(t_storage *b)
{
	b->zr = b->x * b->zoom + b->ofsx;
	b->zi = b->y * b->zoom + b->ofsy;
	b->i = -1;
	while (b->zr * b->zr + b->zi * b->zi < 4 && ++b->i < b->itnum)
	{
		b->tmp = b->zr;
		b->zr = b->zr * b->zr - b->zi * b->zi - 0.8 + (b->cr / WIN_W);
		b->zi = 2 * b->zi * b->tmp + b->ci / WIN_W;
	}
	if (b->coloring)
	{
		if (b->i == b->itnum)
			ppx_on_img(b->x, b->y, 0x000000, b);
		else
			ppx_on_img(b->x, b->y, (b->color * b->i), b);
	}
	else if (b->i == b->itnum)
		ppx_on_img(b->x, b->y, 0x000000, b);
	else
		ppx_on_img(b->x, b->y, 0xFFFFFF, b);
}

static	void	*split_help(void *arr)
{
	t_storage	*bin;
	int			tmp;

	bin = arr;
	tmp = bin->y;
	bin->x = 0;
	while (bin->x < WIN_W)
	{
		bin->y = tmp;
		while (bin->y < bin->y_cap)
		{
			draw_julia(bin);
			++bin->y;
		}
		++bin->x;
	}
	return (arr);
}

void			split_julia(t_storage *box)
{
	t_storage	arr[THREADS_NUM];
	pthread_t	t[THREADS_NUM];
	int			i;

	i = -1;
	while (++i < THREADS_NUM)
	{
		ft_memcpy((void*)&arr[i], (void*)box, sizeof(t_storage));
		arr[i].y = SEGS_HEIGHT * i;
		arr[i].y_cap = SEGS_HEIGHT * (i + 1);
		pthread_create(&t[i], NULL, split_help, &arr[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(box->mlx, box->win, box->img, 0, 0);
}
