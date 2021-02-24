/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:44:55 by nvu               #+#    #+#             */
/*   Updated: 2021/02/24 11:18:45 by nvu              ###   ########lyon.fr   */
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

char					*ft_ptrtoa(void *ptr)
{
	char			*str;
	char			*temp;
	unsigned long	n;

	n = (unsigned long)ptr;
//	printf("%lu|%p\n", n, ptr);
	if (!(temp = ft_ultoa(n)))
		return (NULL);
//	printf("postultoa=%s\n", temp);
	if (!(str = ft_convert_base(temp, "0123456789", "0123456789abcdef")))
	{
		free(temp);
		return (NULL);
	}
	free(temp);
//	printf("str=%s\n", str);
	return (str);
}
