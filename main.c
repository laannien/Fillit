/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:47:53 by djoye             #+#    #+#             */
/*   Updated: 2019/10/10 17:54:39 by uheirloo         ###   ########.fr       */
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
	t_map	*map;

    i = 0;
	fd = open(argv[1], O_RDONLY);
    while((len = read(fd, buf, BUFF_SIZE)) > 0)
    {
		buf[len] = '\0';
		if (check_file_content(buf, len) && i < 26 && argc == 2)
			figures[i] = save_figures(buf, &figures[i], i);
		else
		{	
			write(1, "error\n", 6);
			return (0);
		}
		i++;
	}
	map = (t_map*)malloc(sizeof(t_map));
	map = get_matrix(i, map);
	map = fillit(i, 0, 0, figures, map);
	i = 0;
	while (i < map->size)
	{
		printf("%s\n", map->matrix[i]);
		i++;
	}
	return (0);
}
