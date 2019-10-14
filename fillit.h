/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:49:37 by djoye             #+#    #+#             */
/*   Updated: 2019/10/14 15:00:26 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21
# define MAX_TETRA 26

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
	char			letter;
	int				x[3];
	int				y[3];
	struct s_tetra	*next;
	struct s_tetra	*prev;
}				t_tetra;

typedef struct	s_map
{
	int			size;
	char		**matrix;
}				t_map;

int				check_file_content(char *str, int len);
t_tetra			*save_figure(char *str, t_tetra *ptr, int index, int len);
t_map			*get_matrix(int resize, t_map *map);
int				fillit(t_tetra *p, t_map *map);
int				push_figure(int x, int y, t_tetra *p, t_map *map);

#endif
