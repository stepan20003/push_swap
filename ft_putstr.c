/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ststepan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:58:00 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/21 15:27:02 by ststepan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (write(2, "(null)", 6));
	while (s[count])
		count++;
	write(2, s, count);
	return (count);
}
