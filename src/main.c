/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:14:38 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 09:19:12 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_ps(t_ps *ps, int argc, char **argv)
{
	int		i;
	t_node	*node;

	ps->a.head = NULL;
	ps->a.tail = NULL;
	ps->b.head = NULL;
	ps->b.tail = NULL;
	i = 1;
	while (i < argc)
	{
		node = lst_new(atoi_error(argv[i], NULL));
		if (!node)
		{
			ps_clear(ps);
			exit(EXIT_FAILURE);
		}
		lst_add_back(&ps->a, node);
		i++;
	}
	return (0);
}

static bool	check_args(int argc, char **argv)
{
	int		i;
	int		j;
	bool	error;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (++j < argc)
			if (!str_cmp(argv[i], argv[j]) && i != j)
				return (true);
		atoi_error(argv[i], &error);
		if (error)
			return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc > 1)
	{
		if (check_args(argc, argv))
			put_str_fd("Error\n", STDERR_FILENO);
		else
		{
			init_ps(&ps, argc, argv);
			sort(&ps);
		}
	}
	return (0);
}
