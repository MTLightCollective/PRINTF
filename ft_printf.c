/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:12:24 by mamauss           #+#    #+#             */
/*   Updated: 2024/03/24 13:43:27 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putchar_arg(va_list args);
int		ft_putstr_arg(va_list args);
int		ft_putstr_fd(char *s, int fd);
char	*ft_itoa_arg(va_list args);
int		ft_putnbr_base(va_list args, char *base);
char	*ft_uitoa_arg(va_list args);

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

int	main(void)
{
	char			c;
	char			c2;
	char			s[6] = "hello";
	char			s2[10] = "goodbye";
	int				i;
	int				*p;
	unsigned int	x;
	unsigned int	unsd_int;

	c = 'A';
	c2 = 'B';
	i = 42;
	x = 0x1A3B;
	unsd_int = 0xDEADBEEF;
	printf("les char a imprimer sont %c et %c et %s\n", c, c2, s);
	ft_printf("ma fonction imprime %c et %c et %s les chars\n", c, c2, s);	
	printf("le string a imprimer est %s et %s\n", s, s2);
	ft_printf("ma fonction imprime %s et %s les strings\n ", s, s2);
	printf("Le int a imprimer est %d\n", i);
	ft_printf("ma fonction imprime %d le int\n", i);
	printf("L'adresse de ptr a imprimer est %p\n", &p);
	ft_printf("ma fonction imprime %p comme adresse de ptr\n", &p);
	printf("La valeur du hexa a imprimer est %x\n", x);
	ft_printf("ma fonction imprime %x comme hexadecimal \n", x);
	printf("La valeur du unsd int a imprimer est %X\n", x);
	ft_printf("ma fonction imprime %X comme hexadecimal \n", x);
	printf("La valeur du unsigned int a imprimer est %u\n", unsd_int);
	ft_printf("ma fonction imprime %u comme unsigned int \n", unsd_int);
	printf("La valeur du pourcentage a imprimer est %%\n");
	ft_printf("ma fonction imprime %% comme pourcentage \n");
	ft_printf("un de chaque ! %c %s %d %p %x %X %u 100%%\n", c, s, i, &p, x, x, unsd_int);
	printf("le compte du reel est %d\n", printf("un de chaque ! %c %s %d %p %x %X %u 100%%\n", c, s, i, &p, x, x, unsd_int));
	printf("le compte du mien est %d\n", ft_printf("un de chaque ! %c %s %d %p %x %X %u 100%%\n", c, s, i, &p, x, x, unsd_int));
	printf("le compte du reel pour 1 int est %d\n", printf("un int ! %d\n", i));
	printf("le compte du mien pour 1 int est %d\n", ft_printf("un int ! %d\n", i));
	printf("le compte du reel pour 1 char est %d\n", printf("un char ! %c\n", c));
	printf("le compte du mien pour 1 char est %d\n", ft_printf("un char ! %c\n", c));
	printf("le compte du reel pour 1 str est %d\n", printf("un str ! %s\n", s));
	printf("le compte du mien pour 1 str est %d\n", ft_printf("un str ! %s\n", s));
	printf("le compte du reel pour 1 *p est %d\n", printf("un *p ! %p\n", &p));
	printf("le compte du mien pour 1 *p est %d\n", ft_printf("un *p ! %p\n", &p));


}
