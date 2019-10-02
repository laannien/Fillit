/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:49:37 by djoye             #+#    #+#             */
/*   Updated: 2019/09/27 20:36:46 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define BUFF_SIZE 21

# include <string.h>
# include <ctype.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define int T01[6] = {0, 1, 0, 2, 0, 3};
# define int T02[6] = {1, 0, 2, 0, 3, 0};
# define int T03[6] = {1, 0, 0, 1, 1, 1};
# define int T04[6] = {0, 1, 0, 2, 1, 2};
# define int T05[6] = {1, 0, 1, 1, 1, 2};
# define int T06[6] = {0, 1, 1, 0, 2, 0};
# define int T07[6] = {0, 1, -1, 1, -2, 1};
# define int T08[6] = {1, 0, 0, 1, 0, 2};
# define int T09[6] = {0, 1, 0, 2, -1, 2};
# define int T10[6] = {0, 1, 1, 1, 2, 1};
# define int T11[6] = {1, 0, 2, 0, 2, 1};
# define int T12[6] = {0, 1, 1, 1, 1, 2};
# define int T13[6] = {1, 0, 0, 1, -1, 1};
# define int T14[6] = {0, 1, 1, -1, -1, 2};
# define int T15[6] = {1, 0, 1, 1, 2, 1};
# define int T16[6] = {-1, 1, 0, 1, 1, 1};
# define int T17[6] = {-1, 1, 0, 1, 0, 2};
# define int T18[6] = {0, 1, 1, 1, 0, 2};
# define int T19[6] = {1, 0, 1, 1, 2, 0};

