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
	if (ft_abs(a) <= ft_abs(b))
		return (a);
	return (b);
}

int	abs_max(int a, int b)
{
	if (ft_abs(a) >= ft_abs(b))
		return (a);
	return (b);
}

t_list	*lst_min(t_list *head)
{
	int		n;
	t_list	*node;

	n = head->val;
	node = head;
	while (head)
	{
		if (head->val < n)
		{
			n = head->val;
			node = head;
		}
		head = head->next;
	}
	return (node);
}

t_list	*lst_max(t_list *head)
{
	int		n;
	t_list	*node;

	n = head->val;
	node = head;
	while (head)
	{
		if (head->val > n)
		{
			n = head->val;
			node = head;
		}
		head = head->next;
	}
	return (node);
}
