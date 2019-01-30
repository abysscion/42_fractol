/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 06:45:00 by emayert           #+#    #+#             */
/*   Updated: 2019/01/28 06:45:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	int		is_type_valid(char *str, s_storage *box)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		box->ftype = 0;
	else	if (ft_strcmp(str, "julia") == 0)
				box->ftype = 1;
			else	if (ft_strcmp(str, "dunnoyet") == 0)
						box->ftype = 2;
	if (box->ftype > -1 && box->ftype < 3)
		return (1);
	else
		return (0);			
}

int				main(int ac, char **av)
{
	s_storage *box;

	box = 0x0;
	if (ac == 2)
	{
		box = (s_storage *)malloc(sizeof(s_storage));
		init_box(box);
		if (is_type_valid(av[1], box))
		{
			init_mlx(box);
			init_fractal(box);
			mlx_hook(box->win, 6, 0, mouse_julia, box);
			mlx_key_hook(box->win, key_hook, box);
			mlx_mouse_hook(box->win, mouse_hook, box);
			mlx_loop(box->mlx);
		}
	}
	free_box(box);
	ft_putendl(MSG_USAGE);
	return (0);
}



























// void *inc_x(void *x_void_ptr)
// {
// 	int *x_ptr = (int *)x_void_ptr;

// 	while (++(*x_ptr) < 10)
// 		;

// 	ft_putendl("x increment finished");
// 	return (0x0);
// }

// int main()
// {
// 	int x = 0, y = 0;
// 	pthread_t inc_x_thread;

// 	pthread_create(&inc_x_thread, 0x0, inc_x, &x);
	
// 	while (++y < 10)
// 		;
// 	ft_putendl("y increment finished");

// 	pthread_join(inc_x_thread, 0x0);
// 	return 0;
// }

