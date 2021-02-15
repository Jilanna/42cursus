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

	out = ft_printf("mine|%i|\n", i);
	vout = printf("true|%i|\n", i);
	printf("out = %i, vout = %i\n", out, vout);
	out = ft_printf("-8ici|%-8i|\n", i);
	out = ft_printf("08ici|%08i|\n", i);
	out = ft_printf(".8ici|%.8i|\n", i);
	out = ft_printf("010.8ici|%010.8i|\n", i);
	printf("7vrai:\n");
	vout = printf("8ici|%i|\n", i);
	vout = printf("8ici|%8i|\n", i);
	vout = printf("-8ici|%-8i|\n", i);
	vout = printf("08ici|%08i|\n", i);
	vout = printf(".8ici|%.8i|\n", i);
	vout = printf("010.8ici|%010.8i|\n", i);

	printf("out = %i, vout = %i\n", out, vout);

}
