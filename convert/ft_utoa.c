/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:47:36 by nvu               #+#    #+#             */
/*   Updated: 2021/02/25 09:12:01 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned int		invers(unsigned int n, long i)
{
	unsigned long long	nb;

	nb = 0;
	while (i > 0)
	{
		nb = nb * 10 + (n % 10);
		i--;
	}
	return (nb);
}

static unsigned int		lenght(unsigned int nb)
{
	long				i;

	i = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char					*ft_utoa(unsigned int n, char type)
{
	long		i;
	char		*str;
	char		*cvrt;
	long		max;

	i = lenght(n);
	if (!(str = malloc(sizeof(char) + (i + 1))))
		return (NULL);
	n = invers(n, i);
	max = i;
	i = -1;
	while (++i < max)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
	}
	str[max] = 0;
	if (type == 'u')
		return(str);
	else if (type == 'x')
		cvrt = ft_convert_base(str, "0123456789", "0123456789abcdef");
	else
		cvrt = ft_convert_base(str, "0123456789", "0123456789ABCDEF");
	free(str);
	return (cvrt);
}

