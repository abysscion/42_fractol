/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:15:00 by emayert           #+#    #+#             */
/*   Updated: 2019/01/29 09:15:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_hook(int key, t_storage *box)
{
	if (key == K_ESC)
	{
		free_box(box);
		exit(0);
	}
	else if (key == K_NUM_PLUS)
		box->itnum += ITER_STEP;
	else if (key == K_NUM_MINUS)
		box->itnum -= ITER_STEP;
	if (key == K_1 || key == K_2 || key == K_3 || key == K_4 || key == K_5)
		change_color(key, box);
	if (key == K_J)
		box->mjulia = !box->mjulia;
	if (key == K_R)
		init_fractal(box);
	else
		split_fractal(box);
	if (key == K_H && (box->help_toggled = -box->help_toggled))
		show_help(box);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_storage *box)
{
	if (key == M_MWHEELUP)
		zoom('+', x, y, box);
	else if (key == M_MWHEELDOWN)
		zoom('-', x, y, box);
	split_fractal(box);
	return (0);
}
