/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saver.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:35:50 by djoye             #+#    #+#             */
/*   Updated: 2019/10/08 17:11:16 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// Сохраняет фигуру в виде структуры (отступы х и у + буква)
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

int			main(int argc, char **argv)
{
	int		i;
	t_tetra	figures[26];
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		len;
	int		pt;

	pt = 0;
	fd = open(argv[argc - 1], O_RDONLY);
	while ((len = read(fd, buf, BUFF_SIZE)) > 0 && pt < 26)
	{
		figures[pt] = save_figures(buf, &figures[pt], pt);
		i = 0;
		while (i < 3)
		{
			printf("%d %d\n", figures[pt].x[i], figures[pt].y[i]);
			i++;
		}
		pt++;
	}
	return (0);
}
