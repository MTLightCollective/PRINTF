/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:03:06 by mamauss           #+#    #+#             */
/*   Updated: 2024/03/19 15:40:59 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_putstr_arg(va_list args)
{
	char	*str;
	int		i;

	str = (char *)va_arg(args, char *);
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
