/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:21:50 by mamauss           #+#    #+#             */
/*   Updated: 2024/03/24 16:09:24 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int main(void)
{
    char            c;
    char            c2;
    char            s[6] = "hello";
    char            s2[10] = "goodbye";
    int             i;
    int             *p;
    unsigned int    x;
    unsigned int    unsd_int;

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
    printf("le vrai pour 1 str vide est %s\n", (char *)NULL);
    ft_printf("le mien pour 1 str vide est %s\n", (char *)NULL);
	
}
