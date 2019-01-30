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
#  define K_0			48
#  define K_1			49
#  define K_2			50
#  define K_3			51
#  define K_4			52
#  define K_5			53
#  define K_6			54
#  define K_7			55
#  define K_8			56
#  define K_9			57
#  define K_R			114
#  define K_H			104
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
#  define K_0			29
#  define K_1			18
#  define K_2			19
#  define K_3			20
#  define K_4			21
#  define K_5			23
#  define K_6			22
#  define K_7			26
#  define K_8			28
#  define K_9			25
#  define K_R			15
#  define K_H			4
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