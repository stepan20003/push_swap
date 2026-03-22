/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <agaspary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:08:00 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/22 17:39:21 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	t_stack	*tmp;
	int		pos;
	int		min_pos;
	int		min_val;

	tmp = a;
	pos = 0;
	min_pos = 0;
	min_val = a->value;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

static void	bring_to_top(t_stack **a, int pos, int size, t_ops *ops)
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

void	simple_sort(t_data *data)
{
	int	size;
	int	pos;

	while (data->a)
	{
		size = stack_size(data->a);
		pos = find_min_pos(data->a);
		bring_to_top(&data->a, pos, size, &data->ops);
		funct_pb(&data->a, &data->b, &data->ops);
	}
	while (data->b)
		funct_pa(&data->a, &data->b, &data->ops);
}