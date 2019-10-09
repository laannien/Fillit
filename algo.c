/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpixator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:15:47 by djoye             #+#    #+#             */
/*   Updated: 2019/10/09 12:59:17 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		algo(int	count_fig, t_tetra *p, t_map *map)
{
	int		x;
	int		y;
	int		x_mem;
	int		y_mem;
	int		ind_fig;
	int 	push_fig;

	x_mem = 0;
	y_mem = 0;
	ind_fig = 0;
	while (ind_fig >= 0)
	{
		push_fig = 0;
		if (y_mem != 0)
		{
			y = y_mem;
			y_mem = 0;						
		}
		else	y = 0;
		while (y < map->size)
		{
			if (x_mem != 0)
			{
				x = x_mem + 1;
				x_mem = 0;
			}	
			else	x = 0;
			while (x < map->size)
			{
				if (map->matrix[y][x] == '.')
				{	
					printf("%d", x);
					if (push_figure(x, y, &p[ind_fig], map))
					{
						x_mem = x;
						y_mem = y;
						push_fig++;
						if (push_fig == count_fig)
							return (1);
						ind_fig++;
					}
				}
				x++;
			}
			y++;
		}
//delete figure
		ind_fig--;
	}
	get_matrix(count_fig, map);
	return (0);
}
