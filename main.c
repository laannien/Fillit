/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:47:53 by djoye             #+#    #+#             */
/*   Updated: 2019/10/13 14:53:05 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			get_min_size(int count_fig)
{
	int size;

	size = 2;
	while (count_fig * 4 > size * size)
		size++;
	return (size);
}

static void	*ft_memalloc(size_t size)
{
	void	*s;

	if(!(s = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (--size)
		((char*)s)[size] = 0;
	return (s);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	t_tetra	*figures;
	int		i;
	int		len;
	int		p_len;
	t_map	map;

	if ((argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0
			|| read(fd, NULL, 0) == -1) && write(1, "usage\n", 6))
		return (0);
	i = -1;
	figures = ft_memalloc((sizeof(t_tetra) * 26));
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if ((++i >= 26 || !(check(buf, p_len = len))) && write(1, "error\n", 6))
			return (0);
		figures[i] = save_figures(buf, &figures[i], i, len);
	}
	if (p_len != 20 && write(1, "error\n", 6))
		return (0);
	map.size = get_min_size(i);
	map = *get_matrix(0, &map);
	while (!fillit(i, &figures[0], &map))
		get_matrix(1, &map);
	i = -1;
	while (++i < map.size && write(1, map.matrix[i], map.size))
		write(1, "\n", 1);
	return (close(fd));
}
