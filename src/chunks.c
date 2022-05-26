/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:50:03 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 09:39:55 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	n_higher_val(t_list *lst, int val)
{
	if (!lst)
		return (0);
	if (lst->val > val)
		return (1 + n_higher_val(lst->next, val));
	return (n_higher_val(lst->next, val));
}

void	push_chunks(t_ps *ps)
{
	int		chunk_size;

	chunk_size = lst_size(ps->a) / 5 + !lst_size(ps->a) / 5;
	while (ps->a)
	{
		if (n_higher_val(ps->a, ps->a->val) < chunk_size)
			do_op(PB, ps);
		else
			do_op(RA, ps);
	}
}
