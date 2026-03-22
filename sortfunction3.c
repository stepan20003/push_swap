/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfunction3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ststepan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:10:42 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/21 15:27:41 by ststepan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	funct_rrr(t_stack **a, t_stack **b, t_ops *ops)
{
	t_stack	*temp;
	t_stack	*start;

	if (a && *a && (*a)->next)
	{
		start = *a;
		while (start->next->next)
			start = start->next;
		temp = start->next;
		start->next = NULL;
		temp->next = *a;
		*a = temp;
	}
	if (b && *b && (*b)->next)
	{
		start = *b;
		while (start->next->next)
			start = start->next;
		temp = start->next;
		start->next = NULL;
		temp->next = *b;
		*b = temp;
	}
	ops->rrr++;
	write(1, "rrr\n", 4);
}