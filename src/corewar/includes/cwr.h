/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:21:56 by mschimme          #+#    #+#             */
/*   Updated: 2021/04/10 14:13:14 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CWR_H
# define CWR_H
# include <libft.h>
# include <termios.h>
# include <op.h>
# include "op_lims.h"
# include "visual.h"
# include "cwr_defs.h"
# include "cwr_funcs.h"
# include <sys/ioctl.h>

# ifndef CWR_SCH_MOD
#  define CWR_SCH_MOD
# endif
/*
**	curses.h - для графического режима.
**	ioctl.h - для получения актуальных данных по состоянию терминала.
**	termios.h - для контроля терминального устройства, в т.ч. для очистки
**	машинописного буфера ввода.
*/

#endif
