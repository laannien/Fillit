/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:47:53 by djoye             #+#    #+#             */
/*   Updated: 2019/10/09 13:21:53 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

int			main(int argc, char **argv)
{
    int		fd;
    char	buf[BUFF_SIZE + 1];
    int		i;
    int		len;
	t_tetra	figures[26];
	int		pt;
	int		f; //check fig
//	t_tetra p;
	t_map	map;

    i = 0;
    fd = open(argv[argc - 1], O_RDONLY);
    while((len = read(fd, buf, BUFF_SIZE)) > 0 && i < 26)
    {
		if (check_file_content(buf, len))
		{
			buf[len] = '\0';
			figures[i] = save_figures(buf, &figures[i], i);
			i++;
		}
//		else	return (0);
    }
	f = 0;
	while (f < i)
	{
		pt = 0;
		while (pt < 3)
		{
			printf("%d %d\n", figures[f].x[pt], figures[f].y[pt]);
			pt++;
		}
		f++;
	}
	get_matrix(i, &map);
//	algo(i, &p, &map);
	f = 0;
	while (f < map.size)
	{
		printf("%s\n", map.matrix[f]);
		f++;
	}
	return (0);
}
