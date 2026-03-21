/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ststepan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:05:11 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/21 15:27:40 by ststepan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int first;
	int second;
	int third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		funct_sa(a);
	else if (first > second && second > third)
	{
		funct_sa(a);
		funct_rra(a);
	}
	else if (first > second && second < third && first > third)
		funct_ra(a);
	else if (first < second && second > third && first < third)
	{
		funct_sa(a);
		funct_ra(a);
	}
	else if (first < second && second > third && first > third)
		funct_rra(a);
}