/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:44:55 by nvu               #+#    #+#             */
/*   Updated: 2021/03/01 09:53:29 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char				*invers(char *str, long len)
{
	long	i;
	char	*out;

	if (!(out = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len - i - 1 >= 0)
	{
		out[i] = str[len - i - 1];
		i++;
	}
	free(str);
	return (out);
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
	long			i;
	char			*str;
	long			max;

	i = lenght(n);
	if (!(str = malloc(i + 1)))
		return (NULL);
	max = i;
	i = 0;
	while (i < max)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	str[max] = '\0';
	str = invers(str, max);
	return (str);
}

static char				*ft_ptrnull(t_flags *flags)
{
	char	*str;
	int		n;

	n = 2;
	if (flags->precision == 0)
		n = 1;
	if (!(str = malloc(sizeof(char) * n)))
		return (NULL);
	if (n == 2)
		str[0] = '0';
	str[n - 1] = '\0';
	return (str);
}

char					*ft_ptrtoa(void *ptr, t_flags *flags)
{
	char			*str;
	char			*temp;
	unsigned long	n;

	if (ptr == NULL)
		return (ft_ptrnull(flags));
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
