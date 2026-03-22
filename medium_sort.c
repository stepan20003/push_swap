/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <agaspary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:08:00 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/22 17:39:21 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_stack **a, int pos, int size, t_ops *ops)
{
	if (pos <= size / 2)
		while (pos-- > 0)
			funct_ra(a, ops);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			funct_rra(a, ops);
	}
}

static void	rotate_max_up(t_stack **b, int pos, t_ops *ops)
{
	int	size;

	size = stack_size(*b);
	if (pos <= size / 2)
		while (pos--)
			funct_rb(b, ops);
	else
		while (pos++ < size)
			funct_rrb(b, ops);
}

static void	push_max_to_a(t_stack **a, t_stack **b, t_ops *ops)
{
	t_stack	*tmp;
	t_stack	*max;
	int		pos;
	int		c;

	tmp = *b;
	max = *b;
	pos = 0;
	c = 0;
	while (tmp)
	{
		if (tmp->rank > max->rank)
		{
			max = tmp;
			pos = c;
		}
		tmp = tmp->next;
		c++;
	}
	rotate_max_up(b, pos, ops);
	funct_pa(a, b, ops);
}

static void	process_chunk(t_data *data, int min, int max)
{
	t_stack	*tmp;
	int		pos;
	int		size;

	tmp = data->a;
	pos = 0;
	while (tmp && (tmp->rank < min || tmp->rank > max))
	{
		pos++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		size = stack_size(data->a);
		rotate_to_top(&data->a, pos, size, &data->ops);
		funct_pb(&data->a, &data->b, &data->ops);
		tmp = data->a;
		pos = 0;
		while (tmp && (tmp->rank < min || tmp->rank > max))
		{
			pos++;
			tmp = tmp->next;
		}
	}
}

void	medium_sort(t_data *data)
{
	int	size;
	int	chunk_size;
	int	chunks;
	int	i;

	assign_ranks(data->a);
	size = stack_size(data->a);
	chunks = ft_sqrt(size);
	if (chunks < 1)
		chunks = 1;
	chunk_size = size / chunks;
	i = 0;
	while (i < chunks)
	{
		process_chunk(data, i * chunk_size, (i + 1) * chunk_size - 1);
		i++;
	}
	process_chunk(data, i * chunk_size, size - 1);
	while (data->b)
		push_max_to_a(&data->a, &data->b, &data->ops);
}
