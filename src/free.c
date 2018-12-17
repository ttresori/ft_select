/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:09:44 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/03 18:59:45 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_select.h"

void	free_struct(t_file *s_file)
{
	int i;

	i = 0;
	while (s_file->arg[i] != NULL)
	{
		free(s_file->arg[i]);
		i++;
	}
	free(s_file->arg);
	free(s_file->select);
	free(s_file);
}
