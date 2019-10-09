/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saver.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:35:50 by djoye             #+#    #+#             */
/*   Updated: 2019/10/09 13:16:29 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* Сохраняет фигуру в виде структуры (отступы х и у + буква) */
t_tetra		save_figures(char *str, t_tetra *figure, int index)
{
	int		i;
	int		pos;
	int		pt;

	i = 0;
	pt = -1;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && pt == -1)
		{
			pos = i;
			pt++;
		}
		else if (str[i] == '#')
		{
			figure->x[pt] = i % 5 - pos % 5;
			figure->y[pt] = i / 5 - pos / 5;
			pt++;
		}
		if (pt == 3)
		{
			figure->letter = index + 'A';
			break ;
		}
		i++;
	}
	return (*figure);
}
