/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:29:29 by mamauss           #+#    #+#             */
/*   Updated: 2024/03/24 15:57:37 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	digit_counter_unsd(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	answer_writer_unsd(unsigned int n, char *num_str, size_t len)
{
	num_str[len] = '\0';
	while (len--)
	{
		num_str[len] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_uitoa_arg(va_list args)
{
	size_t			len;
	char			*num_str;
	unsigned int	n;

	n = (unsigned int)va_arg(args, int);
	len = digit_counter_unsd(n);
	num_str = malloc(sizeof(char) * (len + 1));
	if (!num_str)
	{
		free (num_str);
		return (NULL);
	}
	answer_writer_unsd(n, num_str, len);
	free (num_str);
	return (num_str);
}
