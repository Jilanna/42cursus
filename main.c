/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:43:48 by nvu               #+#    #+#             */
/*   Updated: 2021/02/04 20:15:33 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		i = 1233;
	char	c = 'g';
	printf("1nico:\n");
	ft_printf("2coucou\n");
	printf("3vrai:\n");
	printf("4coucou\n");
	printf("5nico:\n");
	ft_printf("6ici|%i|\n", i);
	printf("7vrai:\n");
	printf("8ici|%i|%c|%p|\n", i, c, &i);


}
