/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:47:53 by djoye             #+#    #+#             */
/*   Updated: 2019/10/11 13:22:14 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		i;
	int		len;
	int		prev_len;
	t_tetra	figures[26];
	t_map	map;

	if ((argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0
			|| read(fd, NULL, 0) == -1) && write(1, "usage\n", 6))
		return (0);
	i = -1;
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if ((++i >= 26 || !(check_file(buf, len))) && write(1, "error\n", 6))
			return (0);
		figures[i] = save_figures(buf, &figures[i], i, len);
		prev_len = len;
	}
	if (prev_len != 20 && write(1, "error\n", 6))
		return (0);
//	map = (t_map*)malloc(sizeof(t_map));
	map = *get_matrix(i, &map);
	map = *fillit(i, 0, 0, figures, &map);
	i = -1;
	while (++i < map.size && write(1, map.matrix[i], map.size))
		write(1, "\n", 1);
	return (close(fd));
}
