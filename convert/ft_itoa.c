/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:43:33 by nvu               #+#    #+#             */
/*   Updated: 2021/01/28 14:44:51 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		invers(int n, int i)
{
	int		nb;

	nb = 0;
	while (i > 0)
	{
		nb = nb * 10 + (n % 10);
		i--;
	}
	return (nb);
}

static int		lenght(int nb)
{
	int		i;

	i = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		max;

	i = lenght(n);
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	n = invers(n, i);
	max = i;
	i = 0;
	while (i < max)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	str[max] = 0;
	return (str);
}
