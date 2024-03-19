/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:12:24 by mamauss           #+#    #+#             */
/*   Updated: 2024/03/17 14:22:38 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void	format_specifier(va_list args, char format)
{
	//va_list	args_copy;
	//va_copy(args_copy, args);

	if (format == 'c')
		ft_putchar_arg(args);
	else if (format == 's')
		ft_putstr_arg(args);
	else if (format == 'd' || format == 'i')
		ft_itoa(args);
	/*else if (format == 'p' || format == 'x' || format == 'X')
	
	else if (format == 'u')

	else if (format == '%')*/
	
	va_end(args);
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
	char			c2;
	char			s[6] = "hello"; // pointeur
	char			s2[10] = "goodbye";
	int			i;
	int			*p; // adresse de pointeur
	unsigned int	x; // hexadecimal
	unsigned int	X; // hexadecimal en majuscule
	
	c = 'A';
	c2 = 'B';
	i = 42;
	printf("les char a imprimer sont %c et %c et %s\n", c, c2, s);
	ft_printf("ma fonction imprime %c et %c et %s les chars\n", c, c2, s);	
	printf("le string a imprimer est %s et %s\n", s, s2);
	ft_printf("ma fonction imprime %s et %s les strings\n ", s, s2);
	printf("Le int a imprimer est %d\n", i);
	ft_printf("ma fonction imprime %d le int\n", i);
}	
