/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:43:48 by nvu               #+#    #+#             */
/*   Updated: 2021/02/24 14:43:37 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		i = 12345;
	char	*c = "coca";
	int		out;
	int		vout;
	int		*ptr = &i;

	out = ft_printf("mine|%0-*.*d|%0*.*d|\n", 6, 2, 102, 10, 21, -101);
	vout = printf("true|%-*.*d|%0*.*d|\n", 6, 2, 102, 10, 21, -101);
	printf("out = %i, vout = %i\n", out, vout);/*
	out = ft_printf("mine|%i|%8i|%-8i|%08i|%.8i|%10.8i|\n", i, i, i, i, i, i);
	vout = printf("true|%i|%8i|%-8i|%08i|%.8i|%10.8i|\n", i, i, i, i, i, i);
	printf("out = %i, vout = %i\n", out, vout);
	out = ft_printf("mine|%s|%8s|%-8s|%8s|\n", c, c, c, c);
	vout = printf("true|%s|%8s|%-8s|%8s|\n", c, c, c, c);
	printf("out = %i, vout = %i\n", out, vout);
	out = ft_printf("mine|%p|%p|\n", 18446744073709551615, -18446744073709551615, ptr, ptr);
	vout = printf("true|%p|%p|%-8p|%8p|\n", 18446744073709551615, -18446744073709551615, ptr, ptr);
	printf("out = %i, vout = %i\n", out, vout);

	write(1, &c, 1);
	printf("%c", 0);*/
	return (0);
}
