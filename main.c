/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:43:48 by nvu               #+#    #+#             */
/*   Updated: 2021/02/08 20:57:45 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		i = 1233;
	char	c = 'g';
	int		out;
	int		vout;

	printf("1nico:\n");
	out = bob("2coucou\n");
	printf("3vrai:\n");
	vout = printf("4coucou\n");
	printf("out = %i, vout = %i\n", out, vout);
	printf("5nico:\n");
	out = bob("6ici|%i|\n", i);
	printf("7vrai:\n");
	vout = printf("8ici|%i|%c|%p|\n", i, c, &i);
	printf("out = %i, vout = %i\n", out, vout);


}
