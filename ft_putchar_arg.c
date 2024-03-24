/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:19:50 by mamauss           #+#    #+#             */
/*   Updated: 2024/03/24 13:09:21 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar_arg(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}
