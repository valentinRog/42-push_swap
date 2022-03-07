/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:47:13 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 09:40:25 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_in_order(t_list *head)
{
	t_list	*node;
	int		prev;

	node = lst_min(head);
	prev = node->val;
	node = node->next;
	if (!node)
		node = head;
	while (node != lst_min(head))
	{
		if (node->val < prev)
			return (false);
		prev = node->val;
		node = node->next;
		if (!node)
			node = head;
	}
	return (true);
}

static void	sort_3(t_ps *ps)
{
	if (!is_in_order(ps->a))
	{
		if (dtt(lst_max(ps->a)) > 0)
			while (ps->a != lst_max(ps->a))
				do_op(RA, ps);
		else
			while (ps->a != lst_max(ps->a))
				do_op(RRA, ps);
		do_op(SA, ps);
	}
	if (dtt(lst_min(ps->a)) > 0)
		while (!is_sorted(ps->a))
			do_op(RA, ps);
	else
		while (!is_sorted(ps->a))
			do_op(RRA, ps);
}

void	sort_small(t_ps *ps)
{
	while (lst_size(ps->a) > 3)
	{
		if (dtt(lst_min(ps->a)) > 0)
			while (ps->a != lst_min(ps->a))
				do_op(RA, ps);
		else
			while (ps->a != lst_min(ps->a))
				do_op(RRA, ps);
		do_op(PB, ps);
	}
	sort_3(ps);
	while (ps->b)
		do_op(PA, ps);
}
