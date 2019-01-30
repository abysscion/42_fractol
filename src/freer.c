/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:20:00 by emayert           #+#    #+#             */
/*   Updated: 2019/01/29 09:20:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	free_box(s_storage *box)
{
	if (box)
	{
		if (box->mlx)
		{
			if (box->img)
				mlx_destroy_image(box->mlx, box->img);
			if (box->img_bar)
				mlx_destroy_image(box->mlx, box->img_bar);
			if (box->img_help)
				mlx_destroy_image(box->mlx, box->img_help);
			if (box->win)
				mlx_destroy_window(box->mlx, box->win);
		}
		free(box);
		box = (void *)0;
	}
}
