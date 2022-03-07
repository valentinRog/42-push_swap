/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:33:08 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 11:33:10 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	lst_clear(t_list **lst)
{
	t_list	*swap;

	while (lst && *lst)
	{
		swap = (*lst)->next;
		free(*lst);
		*lst = swap;
	}
}

void	ps_clear(t_ps *ps)
{
	lst_clear(&ps->a);
	lst_clear(&ps->b);
}
