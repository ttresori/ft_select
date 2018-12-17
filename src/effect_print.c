/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:04:43 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/13 02:10:40 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_select.h"

void	de_under(t_file *s_file)
{
	size_t i;

	i = 0;
	if (s_file->arg[s_file->y] == NULL)
		return ;
	if (s_file->select[s_file->y] == 1)
	{
		tputs(tgetstr("mr", NULL), 1, my_outp);
		ft_putstr_fd(s_file->arg[s_file->y], 0);
		tputs(tgetstr("me", NULL), 1, my_outp);
		while (ft_strlen(s_file->arg[s_file->y]) > i++)
			tputs(tgetstr("le", NULL), 1, my_outp);
		return ;
	}
	tputs(tgetstr("ue", NULL), 1, my_outp);
	ft_putstr_fd(s_file->arg[s_file->y], 0);
	tputs(tgetstr("ue", NULL), 1, my_outp);
	while (ft_strlen(s_file->arg[s_file->y]) > i++)
		tputs(tgetstr("le", NULL), 1, my_outp);
}

void	under_current(t_file *s_file)
{
	size_t i;

	i = 0;
	tputs(tgetstr("us", NULL), 1, my_outp);
	if (s_file->select[s_file->y] == 1)
	{
		tputs(tgetstr("mr", NULL), 1, my_outp);
		ft_putstr_fd(s_file->arg[s_file->y], 0);
		tputs(tgetstr("ue", NULL), 1, my_outp);
		tputs(tgetstr("me", NULL), 1, my_outp);
		while (ft_strlen(s_file->arg[s_file->y]) > i++)
			tputs(tgetstr("le", NULL), 1, my_outp);
		return ;
	}
	ft_putstr_fd(s_file->arg[s_file->y], 0);
	tputs(tgetstr("ue", NULL), 1, my_outp);
	while (ft_strlen(s_file->arg[s_file->y]) > i++)
		tputs(tgetstr("le", NULL), 1, my_outp);
}

void	print_select(t_file *s_file)
{
	int i;

	i = 0;
	go_first(s_file);
	clean_line();
	while (s_file->arg[i] != NULL)
	{
		if (s_file->select[i] == 1)
		{
			ft_putstr_fd(s_file->arg[i], STDOUT_FILENO);
			ft_putstr(" ");
		}
		i++;
	}
	ft_putstr_fd("\0", STDOUT_FILENO);
}

void	select_arg(t_file *s_file)
{
	size_t i;

	i = 0;
	if (s_file->select[s_file->y] == -1)
		s_file->select[s_file->y] = 1;
	else
	{
		s_file->select[s_file->y] = -1;
		tputs(tgetstr("me", NULL), 1, my_outp);
		ft_putstr_fd(s_file->arg[s_file->y], 0);
		while (ft_strlen(s_file->arg[s_file->y]) > i++)
			tputs(tgetstr("le", NULL), 1, my_outp);
		moove_down(s_file);
		return ;
	}
	tputs(tgetstr("mr", NULL), 1, my_outp);
	ft_putstr_fd(s_file->arg[s_file->y], 0);
	while (ft_strlen(s_file->arg[s_file->y]) > i++)
		tputs(tgetstr("le", NULL), 1, my_outp);
	moove_down(s_file);
	tputs(tgetstr("me", NULL), 1, my_outp);
}
