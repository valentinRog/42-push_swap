/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:24:49 by vrogiste          #+#    #+#             */
/*   Updated: 2022/05/26 11:24:49 by vrogiste         ###   ########.fr       */
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
