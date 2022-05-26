/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:26:12 by vrogiste          #+#    #+#             */
/*   Updated: 2022/05/26 11:26:12 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_list **head)
{
	t_list	*new_head;

	if (head && lst_size(*head) > 1)
	{
		new_head = (*head)->next;
		(*head)->next = new_head->next;
		if (new_head->next)
			new_head->next->prev = (*head);
		lst_add_front(head, new_head);
	}
}

void	rotate(t_list **head)
{
	t_list	*new_head;

	if (head && lst_size(*head) > 1)
	{
		new_head = (*head)->next;
		new_head->prev = NULL;
		lst_add_back(head, *head);
		*head = new_head;
	}
}

void	reverse_rotate(t_list **head)
{
	t_list	*new_last;

	if (head && lst_size(*head) > 1)
	{
		new_last = lst_last(*head)->prev;
		lst_add_front(head, lst_last(*head));
		new_last->next = NULL;
	}
}

void	push(t_list **a_src, t_list **dst)
{
	t_list	*new_head;

	if (a_src && *a_src && dst)
	{
		new_head = (*a_src)->next;
		if (new_head)
			new_head->prev = NULL;
		lst_add_front(dst, *a_src);
		*a_src = new_head;
	}
}
