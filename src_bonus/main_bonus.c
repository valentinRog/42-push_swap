/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:32:18 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/08 13:55:38 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		node = lst_new(ft_atol(argv[i]));
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

bool	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (++j < argc)
			if (!ft_strcmp(argv[i], argv[j]) && i != j)
				return (false);
		if (*argv[i] == '-')
		{
			if (!*(argv[i] + 1) || !ft_str_isdigit(argv[i] + 1))
				return (false);
		}
		else
			if (!ft_str_isdigit(argv[i]))
				return (false);
		if (ft_strlen(argv[i]) > ft_strlen("-2147483648"))
			return (false);
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (false);
	}
	return (true);
}

void	exec_op(t_ps *ps)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		if (do_op_str(op, ps))
		{
			free(op);
			ps_clear(ps);
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_SUCCESS);
		}
		free(op);
		op = get_next_line(0);
	}
	if (op)
		free(op);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc > 1)
	{
		if (!check_arg(argc, argv))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		init_ps(&ps, false, false);
		fill_arg(&ps, argc, argv);
		exec_op(&ps);
		if (is_sorted(ps.a) && !ps.b)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("K0\n", 1);
		ps_clear(&ps);
	}
	return (0);
}
