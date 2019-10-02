/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:18:15 by djoye             #+#    #+#             */
/*   Updated: 2019/09/27 20:37:46 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_lite (char *str, int len)
{
	int		i;
	int		c_space;
	int		c_hex;
	int     c_dot;

	i = 0;
	c_space = 0;
	c_hex = 0;
	c_dot = 0;
	while (i < len)
	{
		if (str[i] == '\n' && ((i + 1) % 5 == 0 || i % 20 == 0))
			c_space++;
		if (str[i] == '#' && ((i + 1) % 5 != 0 || i % 20 != 0))
			c_hex++;
		if (str[i] == '.' && ((i + 1) % 5 != 0 || i % 20 != 0))
			c_dot++;
		if (c_space >= 4 && c_hex == 4 && c_dot == 12)
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		len;

	fd = open(argv[argc - 1], O_RDONLY);
	while((len = read(fd, buf, BUFF_SIZE)) > 0)
		printf("%d\n", check_lite (buf, len));
	return (0);
}
