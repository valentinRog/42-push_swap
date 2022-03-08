/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:10:53 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/08 08:19:41 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*lst_new(char c)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->c = c;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static void	lst_clear(t_list **lst)
{
	t_list	*swap;

	while (lst && *lst)
	{
		swap = (*lst)->next;
		free(*lst);
		*lst = swap;
	}
}

static void	lst_add_front(t_list **alst, t_list *new_node)
{
	if (alst && new_node)
	{
		new_node->next = *alst;
		new_node->prev = NULL;
		if (*alst)
			(*alst)->prev = new_node;
		*alst = new_node;
	}
}

static char	*lst_to_str(t_list *lst)
{
	t_list	*node;
	size_t	i;
	char	*dst;

	if (!lst)
		return (NULL);
	node = lst;
	i = 1;
	while (node->next && ++i)
		node = node->next;
	dst = malloc((i + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (node)
	{
		dst[i++] = node->c;
		node = node->prev;
	}
	dst[i] = 0;
	return (dst);
}

char	*get_next_line(int fd)
{
	t_list	*lst;
	t_list	*new_node;
	char	c;
	char	*dst;

	lst = NULL;
	c = '\0';
	while (c != '\n' && read(fd, &c, 1) > 0)
	{
		new_node = lst_new(c);
		if (!new_node)
		{
			lst_clear(&lst);
			return (NULL);
		}
		lst_add_front(&lst, new_node);
	}
	dst = lst_to_str(lst);
	lst_clear(&lst);
	return (dst);
}
