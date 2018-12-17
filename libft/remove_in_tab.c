/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_in_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 05:32:02 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/02 18:52:15 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**remove_in_tab(char **tab, int size, int pos)
{
	int		i;
	int		i2;
	char	**new;

	i = 0;
	i2 = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (size))))
		return (NULL);
	while (tab[i2] != NULL)
	{
		if (i2 != pos)
		{
			if (!(new[i] = ft_strdup(tab[i2])))
				return (NULL);
			i++;
			i2++;
		}
		else
			i2++;
	}
	new[i] = NULL;
	return (new);
}
