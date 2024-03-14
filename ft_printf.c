/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:12:24 by mamauss           #+#    #+#             */
/*   Updated: 2024/03/14 12:33:41 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar_arg(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	write (1, &c, 1);
	return (1);
}
void	format_specifier(va_list args, char format)
{
	va_list	args_copy;
	va_copy(args_copy, args);

	if (format == 'c')
		ft_putchar_arg(args_copy);
	/*else if (format == 's')
	
	else if (format == 'p' || format == 'x' || format == 'X')

	else if (format == 'd' || format == 'i')

	else if (format == 'u')

	else if (format == '%')*/
	
	va_end(args_copy);
}
int	ft_printf(char *str, ...)
{
	int	i;
	int	count;
	va_list args;

	va_start(args, str);
	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			format_specifier(args, str[i]);
			count++;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	main()
{
	char			c;  // char
	char			*s; // pointeur
	int				*p; // adresse de pointeur similaire a un hexadecimal
	unsigned int	x; // hexadecimal
	unsigned int	X; // hexadecimal en majuscule
	
	c = 'A';
	printf("le char a imprimer est %c\n", c);
	ft_printf("ma fonction imprime %c le char\n", c);	
}	
