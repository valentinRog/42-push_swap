/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:34:14 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 11:34:17 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *str)
{
	if (str && *str)
		return (1 + ft_strlen(str + 1));
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

bool	ft_str_isdigit(char *str)
{
	if (!str || !*str)
		return (true);
	if (*str >= '0' && *str <= '9')
		return (ft_str_isdigit(str + 1));
	return (false);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

long long int	ft_atol(const char *str)
{
	unsigned long long int	sum;
	int						sign;

	sum = 0;
	sign = 1;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum *= 10;
		sum += *str - '0';
		str++;
	}
	return (sum * sign);
}
