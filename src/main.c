/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:55:26 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/17 01:18:40 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_select.h"

void	print_tab_size(t_file *s_file)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (s_file->arg[i] != NULL)
	{
		if (s_file->select[i] == 1)
		{
			s_file->select[i] = 0;
			s_file->y = i;
			select_arg(s_file);
			i++;
			if (s_file->arg[i] == NULL)
				break ;
		}
		ft_putendl_fd(s_file->arg[i], 0);
		i++;
	}
	s_file->nb_arg = i;
	while (i-- > 0)
		tputs(tgoto(tgetstr("up", NULL), 1, 0), 1, my_outp);
	save_curs_pos();
	s_file->y = 0;
}

void	core(t_file *s_file)
{
	print_tab_size(s_file);
	while (42)
		if ((check_key(s_file)) == 1)
			return ;
}

int		ft_select(int argc, char **argv)
{
	t_term	*s_term;
	t_reset	*s_reset;
	t_file	*s_file;

	s_term = NULL;
	s_reset = NULL;
	if (!(s_file = (t_file*)malloc(sizeof(t_file))))
		return (-1);
	if (!(s_term = (t_term*)malloc(sizeof(t_term))))
		return (-1);
	if (!(s_reset = (t_reset*)malloc(sizeof(t_reset))))
		return (-1);
	init_file(argc, argv, s_file);
	init_term(s_term, s_reset);
	core(s_file);
	if (s_file->return_keys != 2)
		print_select(s_file);
	else
	{
		go_first(s_file);
		ft_putstr_fd("\0", STDOUT_FILENO);
	}
	free_struct(s_file);
	restore_term(s_reset, s_term);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putendl_fd("Usage : ./ft_select [arg] ...\0", 0);
		return (-1);
	}
	if (ft_select(argc, argv) == -1)
		return (-1);
	return (0);
}
