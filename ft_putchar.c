/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <agaspary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:22:02 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/22 17:38:21 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	write(2, &c, 1);
	return (1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	print_disorder(double disorder)
{
	int	whole;
	int	frac;

	whole = (int)(disorder * 100);
	frac = (int)((disorder * 100 - whole) * 100);
	ft_putnbr(whole);
	ft_putchar('.');
	if (frac < 10)
		ft_putchar('0');
	ft_putnbr(frac);
	ft_putchar('%');
	ft_putchar('\n');
}
