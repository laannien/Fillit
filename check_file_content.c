/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:18:15 by djoye             #+#    #+#             */
/*   Updated: 2019/10/14 14:35:15 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check(char *str, int len)
{
	int i;
	int c_line;
	int c_dot;
	int sum;

	i = 0;
	c_line = 0;
	c_dot = 0;
	sum = 0;
	while (i < len)
	{
		if (str[i] == '\n' && ((i + 1) % 5 == 0 || i % 20 == 0))
			c_line++;
		else if (str[i] == '#' && ((i + 1) % 5 != 0 || i % 20 != 0))
			sum += (str[i - 1] == '#' ? 1 : 0) + (str[i + 1] == '#' ? 1 : 0) +
			(str[i + 5] == '#' ? 1 : 0) + (str[i - 5] == '#' ? 1 : 0);
		else if (str[i] == '.' && ((i + 1) % 5 != 0 || i % 20 != 0))
			c_dot++;
		if (c_line >= 3 && c_dot == 12 && (sum == 6 || sum == 8))
			return (1);
		i++;
	}
	return (0);
}
