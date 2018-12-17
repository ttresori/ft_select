/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:06:29 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/17 01:18:53 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_select.h"
#include <stdlib.h>

t_file	*init_file(int argc, char **argv, t_file *s_file)
{
	int i;
	int i2;

	i = 1;
	i2 = 0;
	if (!(s_file->arg = (char**)malloc(sizeof(char*) * (argc))))
		return (NULL);
	if (!(s_file->select = (int*)malloc(sizeof(int) * (argc))))
		return (NULL);
	while (argv[i])
	{
		s_file->arg[i2] = ft_strdup(argv[i]);
		s_file->select[i2] = -1;
		i++;
		i2++;
	}
	s_file->select[i2] = -2;
	s_file->arg[i2] = NULL;
	s_file->return_keys = 0;
	g_file = *s_file;
	init_signal();
	s_file->y = 0;
	return (s_file);
}

void	init_term(t_term *s_term, t_reset *s_reset)
{
	struct winsize w;

	if (tgetent(NULL, getenv("TERM")) == -1)
	{
		ft_putendl("Set term or a valide term.");
		exit(0);
	}
	if (tcgetattr(0, &s_term->term) == -1)
		exit(0);
	if (tcgetattr(0, &s_reset->term) == -1)
		exit(0);
	s_term->term.c_lflag &= ~(ICANON);
	s_term->term.c_lflag &= ~(ECHO);
	s_term->term.c_cc[VMIN] = 1;
	s_term->term.c_cc[VTIME] = 1;
	ioctl(0, TIOCGWINSZ, &w);
	if (tcsetattr(0, TCSANOW, &s_term->term) == -1)
		exit(0);
	g_term = *s_term;
	g_reset = *s_reset;
}

void	restore_term(t_reset *s_reset, t_term *s_term)
{
	if (tcsetattr(0, 0, &s_reset->term))
		return ;
	free(s_reset);
	free(s_term);
}
