/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:55:24 by nvu               #+#    #+#             */
/*   Updated: 2021/01/28 14:19:23 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int				ft_strlen_test(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-'
				|| (str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			return (0);
		j = 0;
		while (str[j])
		{
			if (str[i] == str[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void			ft_forward(char *nbr, unsigned long *i, char *nbrf,
		unsigned long *j)
{
	int	signe;

	signe = 1;
	while (nbr[*i] == 32 || (nbr[*i] >= 9 && nbr[*i] <= 13))
		(*i)++;
	while (nbr[*i] == '+' || nbr[*i] == '-')
	{
		if (nbr[*i] == '-')
			signe *= -1;
		(*i)++;
	}
	if (signe == -1)
	{
		nbrf[*j] = '-';
		(*j)++;
	}
}

int				ft_is_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

unsigned long	ft_savenbr(char c, char *base, unsigned long sortie)
{
	unsigned int	number;
	int				base_len;

	number = 0;
	base_len = ft_strlen_test(base);
	while (base[number] && c != base[number])
		number++;
	sortie = sortie * base_len + number;
	return (sortie);
}

char			*ft_alloc(char *nbrf)
{
	nbrf = malloc(sizeof(char) * 32 + 2);
	if (nbrf == NULL)
		return (NULL);
	return (nbrf);
}
