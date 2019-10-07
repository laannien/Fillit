/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saver.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:35:50 by djoye             #+#    #+#             */
/*   Updated: 2019/10/07 19:18:06 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define	struct	s_point
{
	char    name;
	int     x[3];
	int     y[3];
}           p;

int				saver(*str, *p)
{
	int 		i;
	int			count;
	int			pos;
	int			pt;

	i = 0;
	count = 0;
	pt = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '#' && count == 0)
		{
			pos = i;
			count++;
		}
		else if (str[i] == '#' && count != 0)
		{
			p->x[pt] = (i - pos - 5) % 5;
			p->y[pt] = (i - pos) / 5 + (p->x[pt] < 0 ? 1 : 0);
			pt++;
		}
		if (pt == 3)
			return (p);
		i++;
	}
	return (NULL);
}

int     main(int argc, char **argv)
{
	int     fd;
	char    buf[BUFF_SIZE + 1];
	int     len;

	fd = open(argv[argc - 1], O_RDONLY);
	while((len = read(fd, buf, BUFF_SIZE)) > 0)
		printf("%s\n", saver (buf, &p));
	return (0);
}
