/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:39:25 by mamauss           #+#    #+#             */
/*   Updated: 2024/04/17 14:34:08 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putchar_arg(va_list args);
int		ft_putstr(char *s);
int		ft_putstr_arg(va_list args);
int		ft_putstr_fd(char *s, int fd);
char	*ft_itoa_arg(va_list args);
int		ft_puthexa_arg(va_list args, int i);
char	*ft_uitoa_arg(va_list args);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_printf(const char *str, ...);

#endif /* FT_PRINTF_H */
