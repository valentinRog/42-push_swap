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

static void	init_ps(t_ps *ps)
{
	ps->a = NULL;
	ps->b = NULL;
}

static int	fill_arg(t_ps *ps, int argc, char **argv)
{
	int		i;
	t_list	*node;

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

static bool	check_error(int argc, char **argv)
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
	t_ps ps;

	if (argc > 1)
	{
		if (check_error(argc, argv))
			put_str_fd("Error\n", 2);
		else
		{
			init_ps(&ps);
			fill_arg(&ps, argc, argv);
			sort(&ps);
		}
	}
	return (0);
}
