/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:11:04 by mamauss           #+#    #+#             */
/*   Updated: 2024/03/19 15:49:19 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_puthexa_arg(va_list args)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)va_arg(args, char *);
	while (str[i])
	{
	write(1, &str[i], 1);
	i++;
}
	return (i);
}
