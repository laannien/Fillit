/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:15:47 by djoye             #+#    #+#             */
/*   Updated: 2019/10/09 15:59:19 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*algo(int	count_fig, t_tetra *p, t_map *map)
{
	int		x;
	int		y;
//	int		x_mem;
//	int		y_mem;
	int		ind_fig;
	int 	push_fig;

//	x_mem = 0;
//	y_mem = 0;
	ind_fig = 0;
	while (ind_fig >= 0)
	{
		push_fig = 0;
//		if (y_mem != 0) //???
//		{
//			y = y_mem;
//			y_mem = 0;						
//		}
		y = 0;
		while (y < map->size)
		{
//			if (x_mem != 0) //???  //			{
//				x = x_mem;
//				x_mem = 0;
//			}	
			x = 0;
			while (x < map->size)
			{
				if (map->matrix[y][x] == '.' && push_figure(x, y, &p[ind_fig], map))
				{
					x = 0;
					y = 0;
					push_fig++;
					if (push_fig == count_fig)
						return (map);
					ind_fig++;
				}
				x++;
			}
			y++;
		}
//delete figure
		ind_fig--;
	}
	get_matrix(count_fig, p, map);
	return (map);
}
