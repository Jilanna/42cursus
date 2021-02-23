/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:43:33 by nvu               #+#    #+#             */
/*   Updated: 2021/02/23 10:04:14 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		invers(int n, int i)
{
	int		nb;

	nb = 0;
	while (i > 0)
	{
		nb = nb * 10 + (n % 10);
		n = n / 10;
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
	int		var[2];

	var[1] = 0;
	if (n < 0)
	{
		n = -n;
		var[1] = 1;
	}
	i = lenght(n);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	n = invers(n, i);
	var[0] = i;
	i = -1;
	while (++i < var[0])
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
	}
	str[var[0]] = '\0';
	if (var[1] == 1)
		str = ft_add_before(str, '-', var[0], 1);
	return (str);
}
