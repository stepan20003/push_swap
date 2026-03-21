/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ststepan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:08:41 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/21 15:27:36 by ststepan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_name(int strategy)
{
	if (strategy == SIMPLE)
		return ("simple");
	if (strategy == MEDIUM)
		return ("medium");
	return ("complex");
}

static char	*get_complexity(int strategy)
{
	if (strategy == SIMPLE)
		return ("O(n^2)");
	if (strategy == MEDIUM)
		return ("O(n*sqrt(n))");
	return ("O(n log n)");
}

void	print_bench(double disorder, int strategy)
{
	ft_putstr("Disorder:  ");
	print_disorder(disorder);
	ft_putstr("Strategy:  ");
	ft_putstr(get_name(strategy));
	ft_putchar('\n');
	ft_putstr("Complexity:  ");
	ft_putstr(get_complexity(strategy));
	ft_putchar('\n');
}