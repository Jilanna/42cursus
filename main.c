/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:43:48 by nvu               #+#    #+#             */
/*   Updated: 2021/02/15 18:39:53 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		i = 12345;
	char	c = 'g';
	int		out;
	int		vout;
	int		*ptr = &i;

	out = ft_printf("mine|%i|%8i|%-8i|%08i|%.8i|%10.8i|\n", i, i, i, i, i, i);
	vout = printf("true|%i|%8i|%-8i|%08i|%.8i|%10.8i|\n", i, i, i, i, i, i);
	printf("out = %i, vout = %i\n", out, vout);
	out = ft_printf("mine|%c|%8c|%-8c|%8c|%.8c|%10.8c|\n", c, c, c, c, c, c);
	vout = printf("true|%c|%8c|%-8c|%8c|%.8c|%10.8c|\n", c, c, c, c, c, c);
	printf("out = %i, vout = %i\n", out, vout);
	out = ft_printf("mine|%c|%8c|%-8c|%8c|%.8c|%10.8c|\n", c, c, c, c, c, c);
	vout = printf("true|%c|%8c|%-8c|%8c|%.8c|%10.8c|\n", c, c, c, c, c, c);
	printf("out = %i, vout = %i\n", out, vout);
	out = ft_printf("mine|%c|%8c|%-8c|%8c|%.8c|%10.8c|\n", c, c, c, c, c, c);
	vout = printf("true|%c|%8c|%-8c|%8c|%.8c|%10.8c|\n", c, c, c, c, c, c);
	printf("out = %i, vout = %i\n", out, vout);
	out = ft_printf("mine|%c|%8c|%-8c|%8c|%.8c|%10.8c|\n", c, c, c, c, c, c);
	vout = printf("true|%c|%8c|%-8c|%8c|%.8c|%10.8c|\n", c, c, c, c, c, c);
	printf("out = %i, vout = %i\n", out, vout);
	out = ft_printf("mine|%c|%8c|%-8c|%8c|%.8c|%10.8c|\n", c, c, c, c, c, c);
	vout = printf("true|%c|%8c|%-8c|%8c|%.8c|%10.8c|\n", c, c, c, c, c, c);
	printf("out = %i, vout = %i\n", out, vout);
}
