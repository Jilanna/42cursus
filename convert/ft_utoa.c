/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:47:36 by nvu               #+#    #+#             */
/*   Updated: 2021/03/01 09:04:28 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char			*invers(char *str, int len)
{
	int		i;
	char	*out;

	if (!(out = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len - i - 1 >= 0)
	{
		out[i] = str[len - i - 1];
		i++;
	}
	out[len] = '\0';
	free(str);
	return (out);
}

static unsigned int	lenght(unsigned int nb)
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

static char			*tostr(unsigned int nb, int i)
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

char				*ft_utoa(unsigned int n, char type)
{
	int		len;
	char	*str;
	char	*cvrt;

	len = lenght(n);
	if (!(str = tostr(n, len)))
		return (NULL);
	if (!(str = invers(str, len)))
		return (NULL);
	if (type == 'u')
		return (str);
	else if (type == 'x')
		cvrt = ft_convert_base(str, "0123456789", "0123456789abcdef");
	else
		cvrt = ft_convert_base(str, "0123456789", "0123456789ABCDEF");
	free(str);
	return (cvrt);
}
