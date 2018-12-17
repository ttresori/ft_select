/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:26:00 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/03 18:35:12 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_select.h"

void		moove_up(t_file *s_file)
{
	int i;

	i = 0;
	de_under(s_file);
	if (s_file->y == 0)
	{
		go_last(s_file);
		return ;
	}
	s_file->y--;
	tputs(tgoto(tgetstr("up", NULL), 1, 0), 1, my_outp);
}

void		go_first(t_file *s_file)
{
	de_under(s_file);
	while (s_file->y > 0)
	{
		s_file->y--;
		tputs(tgoto(tgetstr("up", NULL), 1, 0), 1, my_outp);
	}
}

void		go_last(t_file *s_file)
{
	while (s_file->y + 1 < s_file->nb_arg)
	{
		s_file->y++;
		tputs(tgoto(tgetstr("do", NULL), 1, 0), 1, my_outp);
	}
}

void		moove_down(t_file *s_file)
{
	if (s_file->y + 1 == s_file->nb_arg)
	{
		go_first(s_file);
		return ;
	}
	de_under(s_file);
	s_file->y++;
	tputs(tgoto(tgetstr("do", NULL), 1, 0), 1, my_outp);
}
