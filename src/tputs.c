/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tputs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:28:12 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/17 01:22:53 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_select.h"

int		my_outp(int c)
{
	if (!(write(0, &c, 1)))
		return (-1);
	return (0);
}

void	clean_window(void)
{
	char	*res;

	if (!((res = tgetstr("cl", NULL))))
		return ;
	tputs(res, 0, my_outp);
}

void	clean_all_line(void)
{
	char	*res;
	int		i;

	i = 0;
	go_first(&g_file);
	while (i < g_file.nb_arg)
	{
		if (!((res = tgetstr("dl", NULL))))
			return ;
		tputs(res, 0, my_outp);
		i++;
	}
}

void	clean_current_line(void)
{
	char	*res;

	if (!((res = tgetstr("dl", NULL))))
		return ;
	tputs(res, 0, my_outp);
}

void	clean_line(void)
{
	char	*res;

	if (!((res = tgetstr("cd", NULL))))
		return ;
	tputs(res, 0, my_outp);
}
