/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 06:45:00 by emayert           #+#    #+#             */
/*   Updated: 2019/01/28 06:45:30 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__
#  define K_ESC			65307
#  define K_NUM_MULT	65450
#  define K_NUM_DIV		65455
#  define K_NUM_PLUS	65451
#  define K_NUM_MINUS	65453
#  define K_NUM_ENTER	65421
#  define K_NUM_0		65438
#  define K_ARRUP		65362
#  define K_ARRDOWN		65364
#  define K_ARRLEFT		65361
#  define K_ARRRIGHT	65363
#  define M_LMB			1
#  define M_MWHEEL		2
#  define M_RMB			3
#  define M_MWHEELUP	4
#  define M_MWHEELDOWN	5
# else
#  define K_ESC			53
#  define K_NUM_MULT	67
#  define K_NUM_DIV		75
#  define K_NUM_PLUS	69
#  define K_NUM_MINUS	78
#  define K_NUM_ENTER	76
#  define K_NUM_0		82
#  define K_ARRUP		126
#  define K_ARRDOWN		125
#  define K_ARRLEFT		123
#  define K_RRRIGHT		124
#  define M_LMB			1
#  define M_MWHEEL		2
#  define M_RMB			3
#  define M_MWHEELUP	4
#  define M_MWHEELDOWN	5
# endif

#endif