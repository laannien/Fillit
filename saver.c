/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saver.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:35:50 by djoye             #+#    #+#             */
/*   Updated: 2019/10/08 14:49:19 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		saver(char *str, t_tetra *figure, int index)
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
		figures[pt] = saver(buf, &figures[pt], pt);
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
