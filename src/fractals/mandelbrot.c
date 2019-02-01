/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 06:45:00 by emayert           #+#    #+#             */
/*   Updated: 2019/01/28 06:45:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

#ifdef __linux__
# define ZOOM_MULTI 2
# define OFSX_MULTI 2
# define OFSY_MULTI 1.2
#else
# define ZOOM_MULTI 3.5
# define OFSX_MULTI 2.2
# define OFSY_MULTI 1.15
#endif

void			init_mandelbrot(t_storage *box)
{
	box->itnum = ITER_STEP;
	box->zoom = 1.0 / (100.0 * ZOOM_MULTI);
	box->ofsx = -1.0 * OFSX_MULTI;
	box->ofsy = -1.0 * OFSY_MULTI;
}

static	void	draw_mandelbrot(t_storage *b)
{
	b->cr = b->x * b->zoom + b->ofsx;
	b->ci = b->y * b->zoom + b->ofsy;
	b->zr = 0;
	b->zi = 0;
	b->i = -1;
	while (b->zr * b->zr + b->zi * b->zi < 4 && ++b->i < b->itnum)
	{
		b->tmp = b->zr;
		b->zr = b->zr * b->zr - b->zi * b->zi + b->cr;
		b->zi = 2 * b->zi * b->tmp + b->ci;
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
			draw_mandelbrot(bin);
			++bin->y;
		}
		++bin->x;
	}
	return (arr);
}

void			split_mandelbrot(t_storage *box)
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
