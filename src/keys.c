/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:00:38 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/17 01:23:10 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_select.h"

int	key_to_moove(t_file *s_file, char *buf)
{
	if (DOWN)
	{
		moove_down(s_file);
		return (0);
	}
	if (UP)
	{
		moove_up(s_file);
		return (0);
	}
	return (-1);
}

int	help_check_key(t_file *s_file)
{
	if (del_one(s_file) == -1)
	{
		s_file->return_keys = 2;
		return (1);
	}
	return (0);
}

int	check_key(t_file *s_file)
{
	char	buf[3];

	under_current();
	ft_bzero(buf, 3);
	if (read(0, buf, 3))
	{
		if (ESCAPE)
		{
			s_file->return_keys = 2;
			return (1);
		}
		if (SPACE)
			select_arg(s_file);
		if (ENTER)
			return (1);
		if (DEL)
		{
			if (help_check_key(s_file) == 1)
				return (1);
			return (0);
		}
		if (key_to_moove(s_file, buf) == 0)
			return (0);
	}
	return (-1);
}
