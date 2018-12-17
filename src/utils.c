/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:37:31 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/13 02:19:00 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_select.h"

void	refresh_select_arg(t_file *s_file)
{
	int i;

	i = 0;
	while (s_file->arg[i] != NULL)
	{
		if ((i >= s_file->y) && s_file->select[i + 1] != -2)
			s_file->select[i] = s_file->select[i + 1];
		i++;
	}
}

int		del_one(t_file *s_file)
{
	char	**new;

	new = NULL;
	new = remove_in_tab(s_file->arg, s_file->nb_arg--, s_file->y);
	refresh_select_arg(s_file);
	if (s_file->nb_arg == 0)
		return (-1);
	free_split(s_file->arg);
	s_file->arg = new;
	clean_current_line();
	if (s_file->y == s_file->nb_arg)
		moove_up(s_file);
	return (1);
}
