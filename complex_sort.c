/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <agaspary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:08:00 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/22 17:39:21 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_ranks(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	int		rank;

	i = a;
	while (i)
	{
		rank = 0;
		j = a;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->rank = rank;
		i = i->next;
	}
}

static int	max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

static void	radix_pass(t_data *data, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((data->a)->rank >> bit) & 1)
			funct_ra(&data->a, &data->ops);
		else
			funct_pb(&data->a, &data->b, &data->ops);
		i++;
	}
	while (data->b)
		funct_pa(&data->a, &data->b, &data->ops);
}

void	complex_sort(t_data *data)
{
	int	size;
	int	bits;
	int	bit;

	assign_ranks(data->a);
	size = stack_size(data->a);
	bits = max_bits(size);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(data, bit, size);
		bit++;
	}
}
