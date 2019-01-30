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

void	zoom(char sign, int x, int y, s_storage *b)
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