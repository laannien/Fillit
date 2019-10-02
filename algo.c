/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpixator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:15:47 by djoye             #+#    #+#             */
/*   Updated: 2019/09/27 20:39:02 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		algo(int	count_fig, int matrix_size, char ***arr, char **map)
{
	int		x;
	int		y;
	int		x_mem;
	int		y_mem;
	int		num_fig;
	count	vpix;

	x_mem = 0;
	y_mem = 0;
	while (num_fig >= 0)
	{
		vpix = 0;
		if (y_mem != 0)
		{
			y = y_mem;
			y_mem = 0;						
		}
		else	y = 0;
		while (y < matrix_size)
		{
			if (x_mem != 0)
			{
				x = x_mem + 1;
				x_mem = 0;
			}	
			else	x = 0;
			while (x < matrix_size)
			{
				if (map[y][x] == '.')
				{	
					if (ft_vpixator (num_fig, map, x, y))
					{
						x_mem = x;
						y_mem = y;
						vpix++;
						if (vpix == count_fig)
							return (1);
						num_fig++;
					}
				}
				x++;
			}
			y++;
		}
		num_fig--;
	}
	matrix (count_fig, 1);
	return (0);
}
