/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:10:32 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/05 13:10:32 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *lst)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!lst || !lst->head || lst->head == lst->tail)
		return ;
	first = lst->head;
	second = first->next;
	if (!second)
		return ;
	third = second->next;
	if (third)
		third->prev = first;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (!third)
		lst->tail = first;
	else
		third->prev = first;
	lst->head = second;
}

void	rotate(t_list *lst)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!lst || !lst->head || lst->head == lst->tail)
		return ;
	first = lst->head;
	second = first->next;
	last = lst->tail;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	lst->head = second;
	lst->tail = first;
	first->next = NULL;
}

void	reverse_rotate(t_list *lst)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	if (!lst || !lst->head || lst->head == lst->tail)
		return ;
	first = lst->head;
	last = lst->tail;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	first->prev = last;
	last->next = first;
	lst->head = last;
	lst->tail = second_last;
}

void	push(t_list *src, t_list *dst)
{
	t_node	*node;

	if (!src || !dst || !src->head)
		return ;
	node = src->head;
	src->head = node->next;
	if (!src->head)
		src->tail = NULL;
	node->next = dst->head;
	node->prev = NULL;
	if (dst->head)
		dst->head->prev = node;
	dst->head = node;
	if (!dst->tail)
		dst->tail = node;
}
