/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saver.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:35:50 by djoye             #+#    #+#             */
/*   Updated: 2019/10/14 13:26:32 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra	*save_figure(char *str, t_tetra *ptr, int index, int len)
{
	int		i;
	int		pos;
	int		pt;
	t_tetra	*figure;

	i = 0;
	pt = -1;
	if (!(figure = (t_tetra*)malloc(sizeof(t_tetra))))
		return (NULL);
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
	figure->next = NULL;
	figure->prev = ptr;
	return (figure);
}
