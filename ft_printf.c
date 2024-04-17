/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:12:24 by mamauss           #+#    #+#             */
/*   Updated: 2024/04/17 14:33:35 by mamauss          ###   ########.fr       */
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
		j += ft_putstr("0x") + ft_puthexa_arg(args, 3);
	else if (format == 'x')
		j += ft_puthexa_arg(args, 1);
	else if (format == 'X')
		j += ft_puthexa_arg(args, 2);
	else if (format == 'u')
		j += ft_putstr_fd(ft_uitoa_arg(args), 1);
	else if (format == '%')
		j += ft_putchar_fd('%', 1);
	else
		return (0);
	return (j);
}

int	ft_printf(const char *str, ...)
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
