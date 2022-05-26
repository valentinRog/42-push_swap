/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:06:08 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 12:25:38 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dtt(t_list *node)
{
	int		dp;
	int		dn;
	t_list	*temp;

	dp = 0;
	dn = 0;
	temp = node;
	while (temp->prev)
	{
		dp++;
		temp = temp->prev;
	}
	temp = node;
	while (temp)
	{
		dn--;
		temp = temp->next;
	}
	return (abs_min(dp, dn));
}

static int	cost(t_list *node_b, t_ps *ps)
{
	int	c1;
	int	c2;

	c1 = dtt(node_b);
	c2 = dtt(homologue(node_b, ps->a));
	if (c1 < 0 && c2 < 0)
		return (ft_abs(abs_max(c1, c2)));
	if (c1 > 0 && c2 > 0)
		return (ft_abs(abs_max(c1, c2)));
	return (ft_abs(c1) + ft_abs(c2));
}

t_list	*find_min_cost(t_ps *ps)
{
	t_list	*node_b;
	t_list	*min_cost_node;

	node_b = ps->b;
	min_cost_node = ps->b;
	while (node_b)
	{
		if (cost(node_b, ps) < cost(min_cost_node, ps))
			min_cost_node = node_b;
		node_b = node_b->next;
	}
	return (min_cost_node);
}
