/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:26:20 by vrogiste          #+#    #+#             */
/*   Updated: 2022/05/26 11:26:20 by vrogiste         ###   ########.fr       */
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
