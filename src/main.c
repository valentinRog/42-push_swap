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

void	init_ps(t_ps *ps, bool prepare, bool print)
{
	ps->a = NULL;
	ps->b = NULL;
	ps->ops = 0;
	ps->prepare = prepare;
	ps->print = print;
}

int	fill_arg(t_ps *ps, int argc, char **argv)
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

void	exec_best_algo(int argc, char **argv)
{
	t_ps	ps;
	int		prepared;
	int		not_prepared;

	init_ps(&ps, false, false);
	fill_arg(&ps, argc, argv);
	sort(&ps);
	ps_clear(&ps);
	not_prepared = ps.ops;
	init_ps(&ps, true, false);
	fill_arg(&ps, argc, argv);
	sort(&ps);
	ps_clear(&ps);
	prepared = ps.ops;
	if (prepared < not_prepared)
		init_ps(&ps, true, true);
	else
		init_ps(&ps, false, true);
	fill_arg(&ps, argc, argv);
	sort(&ps);
	ps_clear(&ps);
}

bool	check_arg(int argc, char **argv)
{
	int		i;
	int		j;
	bool	error;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (++j < argc)
			if (!ft_strcmp(argv[i], argv[j]) && i != j)
				return (false);
		atoi_error(argv[i], &error);
		if (error)
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!check_arg(argc, argv))
			ft_putstr_fd("Error\n", 2);
		else
			exec_best_algo(argc, argv);
	}
	return (0);
}
