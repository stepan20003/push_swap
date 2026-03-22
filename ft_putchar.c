/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ststepan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:22:02 by ststepan          #+#    #+#             */
/*   Updated: 2026/03/21 16:27:26 by ststepan         ###   ########.fr       */
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
	int whole = (int)(disorder * 100);                // integer part
	int frac = (int)((disorder * 100 - whole) * 100); // 2 decimal part
	ft_putnbr(whole);
	ft_putchar('.');
	if (frac < 10)
		ft_putchar('0'); // leading zero for decimal
	ft_putnbr(frac);
	ft_putchar('%');
	ft_putchar('\n');
}