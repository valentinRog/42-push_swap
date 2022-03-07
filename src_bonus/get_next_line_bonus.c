/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:18:46 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 12:31:06 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	str_add_back(char **str, char c)
{
	char	*dst;
	int		i;

	if (str && *str)
	{
		dst = malloc((ft_strlen(*str) + 2) * sizeof(char));
		if (!dst)
		{
			free(*str);
			exit(EXIT_FAILURE);
		}
		i = -1;
		while ((*str)[++i])
			dst[i] = (*str)[i];
		dst[i++] = c;
		dst[i] = 0;
		free(*str);
		*str = dst;
	}
}

char	*get_next_line(int fd)
{
	char	c;
	char	*dst;
	int		bytes_read;

	c = '\0';
	dst = malloc(sizeof(char));
	if (!dst)
		exit(EXIT_FAILURE);
	*dst = '\0';
	while (c != '\n')
	{
		bytes_read = read(fd, &c, 1);
		if (bytes_read < 0)
		{
			free(dst);
			exit(EXIT_FAILURE);
		}
		if (bytes_read && c != '\n')
			str_add_back(&dst, c);
	}
	return (dst);
}
