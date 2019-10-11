/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:49:37 by djoye             #+#    #+#             */
/*   Updated: 2019/10/11 11:35:12 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

typedef struct	s_tetra
{
	char	letter;
	int		x[3];
	int		y[3];
}				t_tetra;

typedef struct	s_map
{
	int			size;
	char		**matrix;
}				t_map;

int				check_file(char *str, int len);
int				push_figure(int x, int y, t_tetra *p, t_map *map);
t_tetra			save_figures(char *str, t_tetra *figure, int index, int len);
t_map			*get_matrix(int count_fig, t_map *map);
//t_map			*algo(int count_fig, t_tetra *p, t_map *map);
t_map			*fillit(int count_fig, int x, int y, t_tetra *p, t_map *map);

#endif
