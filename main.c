/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:47:53 by djoye             #+#    #+#             */
/*   Updated: 2019/10/14 15:18:40 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				get_min_size(int count_fig)
{
	int size;

	size = 2;
	while (count_fig * 4 > size * size)
		size++;
	return (size);
}

static t_tetra	*read_file(int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		len;
	int		p_len;
	t_tetra	*figure;
	int		i;

	i = 0;
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if ((i >= MAX_TETRA || !(check_file_content(buf, len))) &&
			write(1, "error\n", 6))
			return (NULL);
		if (!figure)
			figure = save_figure(buf, NULL, i, len);
		else
		{
			figure->next = save_figure(buf, figure, i, len);
			figure = figure->next;
		}
		p_len = len;
		i++;
	}
	if (p_len != 20 && write(1, "error\n", 6))
		return (NULL);
	return (figure);
}

int				main(int argc, char **argv)
{
	int		i;
	int		fd;
	t_tetra	*figure;
	t_map	map;

	if ((argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0
			|| read(fd, NULL, 0) == -1) && write(1, "usage\n", 6))
		return (0);
	if (!(figure = read_file(fd)))
		return (0);
	i = 1;
	while (figure->prev)
	{
		i++;
		figure = figure->prev;
	}
	map.size = get_min_size(i);
	map = *get_matrix(0, &map);
	while (!fillit(figure, &map))
		get_matrix(1, &map);
	i = -1;
	while (++i < map.size && write(1, map.matrix[i], map.size))
		write(1, "\n", 1);
	return (close(fd));
}
