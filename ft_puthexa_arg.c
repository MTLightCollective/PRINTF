/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:11:04 by mamauss           #+#    #+#             */
/*   Updated: 2024/04/17 14:18:11 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hexa_nb(unsigned long nbr, char *base, int size, int *counter)
{
	(*counter)++;
	if (nbr >= (unsigned long)size)
		print_hexa_nb(nbr / size, base, size, counter);
	ft_putchar(base[nbr % size]);
}

int	ft_puthexa_arg(va_list args, int i)
{
	int				s;
	unsigned int	nbr;
	unsigned long	nbr2;
	int				count;
	char			*base;

	s = 16;
	count = 0;
	base = "0123456789abcdef";
	if (i == 1 || i == 2)
	{
		nbr = va_arg(args, unsigned int);
		if (i == 2)
			base = "0123456789ABCDEF";
		print_hexa_nb((unsigned long)nbr, base, s, &count);
	}
	if (i == 3)
	{
		nbr2 = va_arg(args, unsigned long);
		print_hexa_nb(nbr2, base, s, &count);
	}
	return (count);
}
