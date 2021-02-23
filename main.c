/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:43:48 by nvu               #+#    #+#             */
/*   Updated: 2021/02/23 23:29:52 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		i = 12345;
	char	c = 0;
	int		out;
	int		vout;
	int		*ptr = &i;

	out = ft_printf("mine| 0*%0-*.*d*0 0*%0*.*d*0 \n", 6, 2, 102, 10, 21, -101);
	vout = printf("true| 0*%-*.*d*0 0*%0*.*d*0 \n", 6, 2, 102, 10, 21, -101);
	printf("out = %i, vout = %i\n", out, vout);
	out = ft_printf("mine|%i|%8i|%-8i|%08i|%.8i|%10.8i|\n", i, i, i, i, i, i);
	vout = printf("true|%i|%8i|%-8i|%08i|%.8i|%10.8i|\n", i, i, i, i, i, i);
	printf("out = %i, vout = %i\n", out, vout);
	out = ft_printf("mine|%c|%8c|%-8c|%8c|\n", c, c, c, c);
	vout = printf("true|%c|%8c|%-8c|%8c|\n", c, c, c, c);
	printf("out = %i, vout = %i\n", out, vout);
	out = ft_printf("mine|%p|%8p|%-8p|%8p|\n", ptr, ptr, ptr, ptr);
	vout = printf("true|%p|%8p|%-8p|%8p|\n", ptr, ptr, ptr, ptr);
	printf("out = %i, vout = %i\n", out, vout);
/*
	write(1, &c, 1);
	printf("%c", 0);*/
	return (0);
}
