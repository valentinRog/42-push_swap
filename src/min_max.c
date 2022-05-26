/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:28:44 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 12:28:45 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	abs_min(int a, int b)
{
	return ((ft_abs(a) <= ft_abs(b)) * a + (ft_abs(b) < ft_abs(a)) * b);
}

int	abs_max(int a, int b)
{
	return ((ft_abs(a) >= ft_abs(b)) * a + (ft_abs(b) > ft_abs(a)) * b);
}

t_list	*lst_min(t_list *lst)
{
	int		n;
	t_list	*node_min;

	n = lst->val;
	node_min = lst;
	while (lst)
	{
		if (lst->val < n)
		{
			n = lst->val;
			node_min = lst;
		}
		lst = lst->next;
	}
	return (node_min);
}

t_list	*lst_max(t_list *lst)
{
	int		n;
	t_list	*node_max;

	n = lst->val;
	node_max = lst;
	while (lst)
	{
		if (lst->val > n)
		{
			n = lst->val;
			node_max = lst;
		}
		lst = lst->next;
	}
	return (node_max);
}
