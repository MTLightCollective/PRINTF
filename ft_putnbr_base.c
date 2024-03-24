/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:46:47 by mamauss           #+#    #+#             */
/*   Updated: 2024/03/24 15:06:06 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1])
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	print_base_nb(unsigned long nbr, char *base, int size, int *counter)
{
	(*counter)++;
	if (nbr >= (unsigned long)size)
		print_base_nb(nbr / size, base, size, counter);
	ft_putchar(base[nbr % size]);
}

int	ft_putnbr_base(va_list args, char *base)
{
	int				s;
	unsigned long	nbr;
	int				count;

	s = 0;
	count = 0;
	nbr = (unsigned long)va_arg(args, unsigned long);
	if (check_base(base) == 1)
	{
		while (base[s] != '\0')
			s++;
		print_base_nb(nbr, base, s, &count);
	}
	return (count);
}
