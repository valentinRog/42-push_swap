/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:12:31 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/05 11:12:31 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_new(int val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = val;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*lst_last(t_node *lst)
{
	if (lst && lst->next)
		return (lst_last(lst->next));
	return (lst);
}

int	lst_size(t_node *lst)
{
	if (lst)
		return (1 + lst_size(lst->next));
	return (0);
}

void	lst_add_front(t_list *lst, t_node *new_node)
{
	if (!lst || !new_node)
		return ;
	if (!lst->head)
	{
		lst->head = new_node;
		lst->tail = new_node;
	}
	else
	{
		new_node->next = lst->head;
		lst->head->prev = new_node;
		lst->head = new_node;
	}
}

void	lst_add_back(t_list *lst, t_node *new_node)
{
	if (!lst || !new_node)
		return ;
	if (!lst->tail)
	{
		lst->head = new_node;
		lst->tail = new_node;
	}
	else
	{
		new_node->prev = lst->tail;
		lst->tail->next = new_node;
		lst->tail = new_node;
	}
}
