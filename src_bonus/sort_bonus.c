/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:34:04 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 11:34:05 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

bool	is_sorted(t_list *head)
{
	if (!head)
		return (true);
	if (head->prev)
		if (!(head->val > head->prev->val))
			return (false);
	return (is_sorted(head->next));
}
