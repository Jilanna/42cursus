/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:43:33 by nvu               #+#    #+#             */
/*   Updated: 2021/02/24 19:13:19 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*invers(char *str, int len)
{
	int		i;
	char	*out;

	if (!(out = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len - i - 1 >= 0)
	{
		out[i] = str[len -i - 1];
		i++;
	}
	out[len] = '\0';
	free(str);
	return (out);
}

static int				lenght(unsigned int nb)
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

static char				*tostr(unsigned int nb, int i)
{
	char			*str;
	int				max;

	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	max = i;
	i = -1;
	while (++i < max)
	{
		str[i] = (nb % 10) + 48;
		nb = nb / 10;
	}
	str[max] = '\0';
	return (str);
}

char					*ft_itoa(int n)
{
	int				neg;
	unsigned int	nb;
	char			*str;
	int				len;

	neg = 0;
	if (n < 0)
	{
		nb = (unsigned int)-n;
		neg = 1;
	}
	else
		nb = (unsigned int)n;
	len = lenght(nb);
	if (!(str = tostr(nb, len)))
		return (NULL);
	if (!(str = invers(str, len)))
		return (NULL);
	if (neg == 1)
		str = ft_add_before(str, '-', len, 1);
	return (str);
}
