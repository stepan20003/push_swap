/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <agaspary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:05:16 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/22 17:45:46 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops	g_ops;

static int	get_strategy(char *flag)
{
	if (ft_strcmp(flag, "--simple") == 0)
		return (SIMPLE);
	if (ft_strcmp(flag, "--medium") == 0)
		return (MEDIUM);
	if (ft_strcmp(flag, "--complex") == 0)
		return (COMPLEX);
	if (ft_strcmp(flag, "--adaptive") == 0)
		return (ADAPTIVE);
	if (ft_strcmp(flag, "--bench") == 0)
		return (-1);
	return (-2);
}

static void	parse_flags(t_data *data, int *argc, char ***argv)
{
	int	flag;
	int	strategy_set;

	strategy_set = 0;
	while (*argc > 1 && (*argv)[1][0] == '-' && (*argv)[1][1] == '-')
	{
		flag = get_strategy((*argv)[1]);
		if (flag == -2)
			ft_error();
		else if (flag == -1)
			data->bench = 1;
		else
		{
			if (strategy_set)
				ft_error();
			data->strategy = flag;
			strategy_set = 1;
		}
		(*argv)++;
		(*argc)--;
	}
}

static void	run_sort(t_data *data)
{
	if (data->strategy == SIMPLE)
		simple_sort(&data->a, &data->b);
	else if (data->strategy == MEDIUM)
		medium_sort(&data->a, &data->b);
	else if (data->strategy == COMPLEX)
		complex_sort(&data->a, &data->b);
	else
		adaptive_sort(data);
}

static void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->strategy = ADAPTIVE;
	data->bench = 0;
	data->disorder = 0;
	g_ops.sa = 0;
	g_ops.sb = 0;
	g_ops.ss = 0;
	g_ops.pa = 0;
	g_ops.pb = 0;
	g_ops.ra = 0;
	g_ops.rb = 0;
	g_ops.rr = 0;
	g_ops.rra = 0;
	g_ops.rrb = 0;
	g_ops.rrr = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		orig_strat;

	if (argc < 2)
		return (0);
	init_data(&data);
	parse_flags(&data, &argc, &argv);
	if (argc < 2)
		return (0);
	parse_input(argc - 1, argv + 1, &data.a);
	data.disorder = compute_disorder(data.a);
	orig_strat = data.strategy;
	if (is_sorted(data.a))
	{
		if (data.bench)
			print_bench(data.disorder, orig_strat, data.strategy);
		return (free_stack(data.a), 0);
	}
	run_sort(&data);
	if (data.bench)
		print_bench(data.disorder, orig_strat, data.strategy);
	free_stack(data.a);
	free_stack(data.b);
	return (0);
}
