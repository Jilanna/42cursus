/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:44:55 by nvu               #+#    #+#             */
/*   Updated: 2021/02/09 14:14:15 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned long	invers(unsigned long n, long i)
{
	unsigned long long	nb;

	nb = 0;
	while (i > 0)
	{
		nb = nb * 10 + (n % 10);
		n /= 10;
		i--;
	}
	return (nb);
}

static unsigned long	lenght(unsigned long nb)
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

static char				*ft_ultoa(unsigned long n)
{
	long				i;
	char				*str;
	long				max;

	i = lenght(n);
	if (!(str = malloc(i + 1)))
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
	str[max] = '\0';
	return (str);
}

char					 *ft_ptrtoa(void *ptr)
{
	char				*str;
	char				*temp;
	unsigned long		n;

	n = (unsigned long)ptr;
	if (!(temp = ft_ultoa(n)))
		return (NULL);
	if (!(str = ft_convert_base(temp, "0123456789", "0123456789abcdef")))
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (str);
}
