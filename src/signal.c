/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 02:53:10 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/17 01:25:47 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_select.h"

static void		restore_term_kill(t_reset *s_reset)
{
	if (tcsetattr(0, 0, &s_reset->term))
		return ;
}

static void	signal_handler(int sig)
{
	if (sig == SIGKILL)
	{
		restore_curs_pos();
		restore_term_kill(&g_reset);
		exit(0);
	}
	if (sig == SIGINT)
	{
		restore_curs_pos();
		restore_term_kill(&g_reset);
		exit(0);
	}
	if (sig == SIGTERM)
	{
		restore_curs_pos();
		restore_term_kill(&g_reset);
		exit(0);
	}
}

	void		init_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGTERM, signal_handler);
}
