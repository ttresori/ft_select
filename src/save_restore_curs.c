/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:34:40 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/03 18:37:40 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_select.h"

void	save_curs_pos(void)
{
	tputs(tgoto(tgetstr("sc", NULL), 1, 0), 1, my_outp);
}

void	restore_curs_pos(void)
{
	tputs(tgoto(tgetstr("rc", NULL), 1, 0), 1, my_outp);
}
