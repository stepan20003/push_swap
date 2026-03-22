/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ststepan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:08:41 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/22 17:00:00 by ststepan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_complexity(int strategy)
{
	if (strategy == SIMPLE)
		return ("O(n^2)");
	if (strategy == MEDIUM)
		return ("O(n*sqrt(n))");
	if (strategy == COMPLEX)
		return ("O(n log n)");
	return ("Adaptive");
}

static void	print_strategy(int orig_strat, int used_strat)
{
	ft_putstr("[bench] strategy:  ");
	if (orig_strat == ADAPTIVE && used_strat != ADAPTIVE)
	{
		ft_putstr("Adaptive / ");
		ft_putstr(get_complexity(used_strat));
	}
	else if (orig_strat == ADAPTIVE)
		ft_putstr("Adaptive");
	else if (orig_strat == SIMPLE)
		ft_putstr("Simple / O(n^2)");
	else if (orig_strat == MEDIUM)
		ft_putstr("Medium / O(n*sqrt(n))");
	else
		ft_putstr("Complex / O(n log n)");
	ft_putchar('\n');
}

static void	print_ops_line1(void)
{
	ft_putstr("[bench] sa: ");
	ft_putnbr(g_ops.sa);
	ft_putstr("  sb: ");
	ft_putnbr(g_ops.sb);
	ft_putstr("  ss: ");
	ft_putnbr(g_ops.ss);
	ft_putstr("  pa: ");
	ft_putnbr(g_ops.pa);
	ft_putstr("  pb: ");
	ft_putnbr(g_ops.pb);
	ft_putchar('\n');
}

static void	print_ops_line2(void)
{
	ft_putstr("[bench] ra: ");
	ft_putnbr(g_ops.ra);
	ft_putstr("  rb: ");
	ft_putnbr(g_ops.rb);
	ft_putstr("  rr: ");
	ft_putnbr(g_ops.rr);
	ft_putstr("  rra: ");
	ft_putnbr(g_ops.rra);
	ft_putstr("  rrb: ");
	ft_putnbr(g_ops.rrb);
	ft_putstr("  rrr: ");
	ft_putnbr(g_ops.rrr);
	ft_putchar('\n');
}

void	print_bench(double disorder, int orig_strat, int used_strat)
{
	int	total;

	total = g_ops.sa + g_ops.sb + g_ops.ss + g_ops.pa + g_ops.pb;
	total += g_ops.ra + g_ops.rb + g_ops.rr + g_ops.rra + g_ops.rrb + g_ops.rrr;
	ft_putstr("[bench] disorder:  ");
	print_disorder(disorder);
	print_strategy(orig_strat, used_strat);
	ft_putstr("[bench] total_ops:  ");
	ft_putnbr(total);
	ft_putchar('\n');
	print_ops_line1();
	print_ops_line2();
}
