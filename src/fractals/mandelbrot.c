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

void			init_mandelbrot(s_storage *box)
{
	box->color = 0x000109;
	box->itnum = ITER_STEP;
	box->zoom = 200;
	box->ofsx = -2.0;
	box->ofsy = -1.2;
}

static	void	draw_mandelbrot(s_storage *b)
{
	b->cr = b->x / b->zoom + b->ofsx;
	b->ci = b->y / b->zoom + b->ofsy;
	b->zr = 0;
	b->zi = 0;
	b->i = 0;
	while (b->zr * b->zr + b->zi * b->zi < 4 && b->i < b->itnum)
	{
		b->tmp = b->zr;
		b->zr = b->zr * b->zr - b->zi * b->zi + b->cr;
		b->zi = 2 * b->zi * b->tmp + b->ci;
		b->i++;
	}
	if (b->i == b->itnum)
		ppx_on_img(b->x, b->y, 0x000000, b);
	else
		ppx_on_img(b->x, b->y, (b->color * b->i), b);
}

static	void	*split_help(void *arr)
{
	s_storage	*bin;
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
			bin->y++;
		}
		bin->x++;
	}
	return (arr);
}

void			split_mandelbrot(s_storage *box)
{
	s_storage	arr[THREADS_NUM];
	pthread_t	t[THREADS_NUM];
	int			i;

	i = -1;
	while (++i < THREADS_NUM)
	{
		ft_memcpy((void*)&arr[i], (void*)box, sizeof(s_storage));
		arr[i].y = SEGS_HEIGHT * i;
		arr[i].y_cap = SEGS_HEIGHT * (i + 1);
		pthread_create(&t[i], NULL, split_help, &arr[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(box->mlx, box->win, box->img, 0, 0);
}
