/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:12:24 by mamauss           #+#    #+#             */
/*   Updated: 2024/03/24 15:44:58 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	format_specifier(va_list args, char format)
{
	int	j;

	j = 0;
	if (format == 'c')
		j += ft_putchar_arg(args);
	else if (format == 's')
		j += ft_putstr_arg(args);
	else if (format == 'd' || format == 'i')
		j += ft_putstr_fd(ft_itoa_arg(args), 1);
	else if (format == 'p')
	{
		j += ft_putstr_fd("0x", 1);
		j += ft_putnbr_base(args, "0123456789abcdef");
	}
	else if (format == 'x')
		j += ft_putnbr_base(args, "0123456789abcdef");
	else if (format == 'X')
		j += ft_putnbr_base(args, "0123456789ABCDEF");
	else if (format == 'u')
		j += ft_putstr_fd(ft_uitoa_arg(args), 1);
	else if (format == '%')
		j += ft_putchar_fd('%', 1);
	va_end(args);
	return (j);
}

int	ft_printf(char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += format_specifier(args, str[++i]);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
