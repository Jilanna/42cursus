/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:43:48 by nvu               #+#    #+#             */
/*   Updated: 2021/02/26 11:53:51 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		i = 8;
	char	c = 'a';;
	int		out;
	int		vout;
	int		*ptr = &i;
	int		a = -4;
	int		b = 0;
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";

	out = ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j);
	printf("\n");
	vout = printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j);
	printf("\nout = %i, vout = %i\n", out, vout);
/*	out = ft_printf("mine|%i|%8i|%-8i|%08i|%.8i|%10.8i|\n", i, i, i, i, i, i);
	vout = printf("true|%i|%8i|%-8i|%08i|%.8i|%10.8i|\n", i, i, i, i, i, i);
	printf("out = %i, vout = %i\n", out, vout);*/
//	out = ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j);
//	printf("\n");
//	vout = printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j);
/*	printf("\nout = %i, vout = %i\n", out, vout);
	out = ft_printf("mine|%p|%p|\n", 18446744073709551615, -18446744073709551615, ptr, ptr);
	vout = printf("true|%p|%p|%-8p|%8p|\n", 18446744073709551615, -18446744073709551615, ptr, ptr);
	printf("out = %i, vout = %i\n", out, vout);

	write(1, &c, 1);
	printf("%c", 0);*/
	return (0);
}
