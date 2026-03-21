/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_fuct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ststepan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:05:33 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/21 15:26:47 by ststepan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_data *data)
{
	if (data->disorder < 0.2)
	{
		data->strategy = SIMPLE;
		simple_sort(&data->a, &data->b);
	}
	else if (data->disorder < 0.5)
	{
		data->strategy = MEDIUM;
		medium_sort(&data->a, &data->b);
	}
	else
	{
		data->strategy = COMPLEX;
		complex_sort(&data->a, &data->b);
	}
}

double	compute_disorder(t_stack *a)
{
	t_stack *i_node;
	t_stack *j_node;
	int mistakes;
	int total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i_node = a;
	while (i_node)
	{
		j_node = i_node->next;
		while (j_node)
		{
			total_pairs++;
			if (i_node->value > j_node->value)
				mistakes++;
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}