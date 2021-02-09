/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:43:48 by nvu               #+#    #+#             */
/*   Updated: 2021/02/09 15:34:05 by nvu              ###   ########lyon.fr   */
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

	printf("1nico:\n");
	out = bob("2coucou\n");
	printf("3vrai:\n");
	vout = printf("4coucou\n");
	printf("out = %i, vout = %i\n", out, vout);
	printf("5nico:\n");
	out = bob("6ici|%i|\n", i);
	out = bob("6ici|%8i|\n", i);
	out = bob("6ici|%-8i|\n", i);
	out = bob("6ici|%08i|\n", i);
	out = bob("6ici|%.8i|\n", i);
	out = bob("6ici|%010.8i|\n", i);
	printf("7vrai:\n");
	vout = printf("8ici|%i|\n", i);
	vout = printf("8ici|%8i|\n", i);
	vout = printf("8ici|%-8i|\n", i);
	vout = printf("8ici|%08i|\n", i);
	vout = printf("8ici|%.8i|\n", i);
	vout = printf("8ici|%010.8i|\n", i);
	printf("out = %i, vout = %i\n", out, vout);


}
