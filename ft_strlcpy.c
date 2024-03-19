/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:33:32 by mamauss           #+#    #+#             */
/*   Updated: 2024/03/19 16:18:10 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	len2;

	len = 0;
	len2 = 0;
	while (src[len] != '\0')
		len++;
	if (dstsize == 0)
		return (len);
	while (src[len2] != '\0' && (len2 < (dstsize - 1)))
	{
		dst[len2] = src[len2];
		len2++;
	}
	if (dstsize != 0)
		dst[len2] = '\0';
	return (len);
}
