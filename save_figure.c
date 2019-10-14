/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:35:50 by djoye             #+#    #+#             */
/*   Updated: 2019/10/14 17:00:08 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra	*save_figure(char *str, t_tetra *ptr, int index, int len)
{
	int		i;
	int		pos;
	int		pt;
	t_tetra	*figure;

	i = -1;
	pt = -2;
	if (!(figure = (t_tetra*)malloc(sizeof(t_tetra))))
		return (NULL);
	while (++i < len && pt < 3)
	{
		if (str[i] == '#')
		{
			if (++pt >= 0)
			{
				figure->x[pt] = i % 5 - pos % 5;
				figure->y[pt] = i / 5 - pos / 5;
			}
				else pos = i;
		}
	}
	figure->letter = index + 'A';
	figure->next = NULL;
	figure->prev = ptr;
	return (figure);
}
