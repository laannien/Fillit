/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:18:15 by djoye             #+#    #+#             */
/*   Updated: 2019/10/04 14:17:20 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// !!! Дописать функцию проверки фигуры перед возвратом 1

// Проверяет валидность содержания файла пофигурно
// В файле должно быть до 26 матриц 4х4, в каждой 5 '\n', 4 '#', а остальное пространство занято 12 '.'
// Записывает правильную фигуру в массив в виде строки
// Возвращает 1 если условия выполнены
int		check_file_content(char *str, int len, char *dest)
{
	int		i;
	int		c_line;
	int		c_hex;
	int     c_dot;

	i = 0;
	c_line = 0;
	c_hex = 0;
	c_dot = 0;

	// Проверяет символ в прочитанном буфере на валидность
	// нахождения '\n' в конце строки и между буферами, подсчёт '#' и '.'
	while (i < len)
	{
		if (str[i] == '\n' && ((i + 1) % 5 == 0 || i % 20 == 0))
			c_line++;
		else if (str[i] == '#' && ((i + 1) % 5 != 0 || i % 20 != 0))
			c_hex++;
		else if (str[i] == '.' && ((i + 1) % 5 != 0 || i % 20 != 0))
			c_dot++;
		else
			break ;
		dest[i] = str[i];
		if (c_line >= 3 && c_hex == 4 && c_dot == 12)
		{
			dest[len] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	char 	dest[26][BUFF_SIZE + 1];
	int		i;
	int		len;

	i = 0;
	fd = open(argv[argc - 1], O_RDONLY);
	while((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		printf("%d\n", check_file_content(buf, len, dest[i]));
		printf("%s\n", dest[i]);
		i++;
	}
	return (0);
}
