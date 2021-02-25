/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:43:48 by nvu               #+#    #+#             */
/*   Updated: 2021/02/25 09:13:33 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		i = 1234;
	char	c = 0;
	int		out;
	int		vout;
	int		*ptr = &i;
/*
	out = ft_printf("mine|%0*.0d|%0*.10d|\n", -21, 2147483647, 21, -2147483648);
	vout = printf("true|%0*.0d|%0*.10d|\n", -21, 2147483647, 21, -2147483648);
	printf("out = %i, vout = %i\n", out, vout);
	
	out = ft_printf("mine|%i|%8i|%-8i|%08i|%.8i|%10.8i|\n", i, i, i, i, i, i);
	vout = printf("true|%i|%8i|%-8i|%08i|%.8i|%10.8i|\n", i, i, i, i, i, i);
	printf("out = %i, vout = %i\n", out, vout);*/
	out = ft_printf("mine|%10u|%4u|\n", 123, -12);
	vout = printf("true|%10u|%4u|\n", 123, -12);
	printf("out = %i, vout = %i\n", out, vout);/*
	out = ft_printf("mine|%p|%p|\n", 18446744073709551615, -18446744073709551615, ptr, ptr);
	vout = printf("true|%p|%p|%-8p|%8p|\n", 18446744073709551615, -18446744073709551615, ptr, ptr);
	printf("out = %i, vout = %i\n", out, vout);

	write(1, &c, 1);
	printf("%c", 0);*/
	return (0);
}
