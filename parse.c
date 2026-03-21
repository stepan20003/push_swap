/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ststepan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:24:41 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/21 15:29:47 by ststepan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	process_number(char *str, t_stack **a, char **numbers, int j)
{
	t_stack	*new;
	long	value;

	if (!is_number(str))
		free_and_error(numbers, j);
	value = ft_atol(str);
	if (value < INT_MIN || value > INT_MAX)
		free_and_error(numbers, j);
	if (is_duplicate(*a, (int)value))
		free_and_error(numbers, j);
	new = stack_new((int)value);
	if (!new)
		free_and_error(numbers, j);
	stack_add_back(a, new);
}

void	parse_input(int count, char **argv, t_stack **a)
{
	char **numbers;
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			ft_error();
		j = 0;
		while (numbers[j])
		{
			process_number(numbers[j], a, numbers, j);
			j++;
		}
		free_arr(numbers, j);
		i++;
	}
}
