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

static void	sort_arr(int *array, int n)
{
	int		i;
	int		j;
	int		temp;
	bool	swapped;

	i = 0;
	swapped = true;
	while (swapped)
	{
		j = 0;
		swapped = false;
		while (j < n - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;
			}
			j++;
		}
		i++;
	}
}

static int	median_a(t_ps *ps)
{
	t_list	*node;
	int		*arr;
	int		i;

	node = ps->a;
	arr = malloc(sizeof(int) * lst_size(ps->a));
	if (!arr)
	{
		ps_clear(ps);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (node)
	{
		arr[i++] = node->val;
		node = node->next;
	}
	sort_arr(arr, lst_size(ps->a));
	return (arr[lst_size(ps->a) / 2]);
}

static bool	has_val_below(t_list *head, int n)
{
	t_list	*node;

	node = head;
	while (node)
	{
		if (node->val < n)
			return (true);
		node = node->next;
	}
	return (false);
}

void	prepare(t_ps *ps)
{
	int	med;

	med = median_a(ps);
	while (has_val_below(ps->a, med))
	{
		if (ps->a->val < med)
			do_op(PB, ps);
		else
			do_op(RA, ps);
	}
	while (lst_size(ps->b) > 2)
		do_op(PA, ps);
}
