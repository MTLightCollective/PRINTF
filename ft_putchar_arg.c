/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:19:50 by mamauss           #+#    #+#             */
/*   Updated: 2024/04/17 14:38:26 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar_arg(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	if (write(1, &c, 1) <= 0)
		return (-1);
	return (1);
}
