/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ststepan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:05:54 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/21 15:26:53 by ststepan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_arr(char **arr, int j)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < j)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_and_error(char **arr, int j)
{
	free_arr(arr, j);
	ft_error();
}
