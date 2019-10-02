/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:47:53 by djoye             #+#    #+#             */
/*   Updated: 2019/09/27 19:11:09 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
//# include "fillit.h"
#define BUFF_SIZE 21

char        **matrix (int count_fig);

int     main(int argc, char **argv)
{
//int T01[6] = {0, 1, 0, 2, 0, 3};
//int T02[6] = {1, 0, 2, 0, 3, 0};
//int T03[6] = {1, 0, 0, 1, 1, 1};
//int T04[6] = {0, 1, 0, 2, 1, 2};
//# define int T05[6] = {1, 0, 1, 1, 1, 2};
//# define int T06[6] = {0, 1, 1, 0, 2, 0};
//# define int T07[6] = {0, 1, -1, 1, -2, 1};
//# define int T08[6] = {1, 0, 0, 1, 0, 2};
//# define int T09[6] = {0, 1, 0, 2, -1, 2};
//# define int T10[6] = {0, 1, 1, 1, 2, 1};
//# define int T11[6] = {1, 0, 2, 0, 2, 1};
//# define int T12[6] = {0, 1, 1, 1, 1, 2};
//# define int T13[6] = {1, 0, 0, 1, -1, 1};
//# define int T14[6] = {0, 1, 1, -1, -1, 2};
//# define int T15[6] = {1, 0, 1, 1, 2, 1};
//# define int T16[6] = {-1, 1, 0, 1, 1, 1};
//# define int T17[6] = {-1, 1, 0, 1, 0, 2};
//# define int T18[6] = {0, 1, 1, 1, 0, 2};
//# define int T19[6] = {1, 0, 1, 1, 2, 0};


//int     check_lite (char *str);
	int		fd;
	int		len;
	int		i;
	int		count_fig;
	char	buf[BUFF_SIZE + 1];

	i = 0;
	count_fig = 2;
//	fd = open(argv[argc - 1], O_RDONLY);
//	len = read(fd, buf, BUFF_SIZE);
//	printf("%d\n", check_lite(buf));
	matrix (count_fig);
	return (0);
}
