/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saver.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:35:50 by djoye             #+#    #+#             */
/*   Updated: 2019/10/12 17:13:45 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra	save_figures(char *str, t_tetra *figure, int index, int len)
{
	int		i;
	int		pos;
	int		pt;

	i = 0;
	pt = -1;
	while (i < len)
	{
		if (str[i] == '#')
		{
			if (pt == -1)
				pos = i;
			else
			{
				figure->x[pt] = i % 5 - pos % 5;
				figure->y[pt] = i / 5 - pos / 5;
			}
			pt++;
		}
		if (pt == 3)
			break ;
		i++;
	}
	figure->letter = index + 'A';
	return (*figure);
}
