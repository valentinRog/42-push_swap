/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:34:29 by vrogiste          #+#    #+#             */
/*   Updated: 2023/03/05 20:07:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	str_len(const char *str)
{
	if (str && *str)
		return (1 + str_len(str + 1));
	return (0);
}

void	put_str_fd(const char *s, int fd)
{
	if (s)
		write(fd, s, str_len(s));
}

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	atoi_error(char *str, bool *error)
{
	long long int			sum;
	int						sign;
	bool					error_val;

	sum = 0;
	sign = 1;
	error_val = false;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign = -1;
	if (!*str)
		error_val = true;
	while (*str >= '0' && *str <= '9')
	{
		sum *= 10;
		sum += *str - '0';
		if ((sum * sign) > INT_MAX || (sum * sign) < INT_MIN)
			error_val = true;
		str++;
	}
	if (*str)
		error_val = true;
	if (error)
		*error = error_val;
	return (sum * sign);
}
