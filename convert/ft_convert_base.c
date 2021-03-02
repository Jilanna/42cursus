/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:07:30 by nvu               #+#    #+#             */
/*   Updated: 2021/03/01 09:52:36 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			ft_nbr_to(unsigned long nb, char *base, char *nbrf,
		unsigned long *j)
{
	unsigned long	taille;

	taille = ft_strlen_test(base);
	if (nb > (taille - 1))
	{
		ft_nbr_to(nb / taille, base, nbrf, j);
		ft_nbr_to(nb % taille, base, nbrf, j);
	}
	else
	{
		nbrf[*j] = base[nb];
		(*j)++;
	}
}

unsigned long	ft_conv(char *nbr, char *base_from, unsigned long *i)
{
	unsigned long	sortie;

	sortie = 0;
	while (nbr[*i] && ft_is_in_base(nbr[*i], base_from))
	{
		sortie = ft_savenbr(nbr[*i], base_from, sortie);
		(*i)++;
	}
	return (sortie);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*nbrf;
	unsigned long	i;
	unsigned long	j;
	unsigned long	out;

	nbrf = NULL;
	i = 0;
	j = 0;
	if (ft_strlen_test(base_from) < 2 || ft_strlen_test(base_to) < 2)
		return (NULL);
	nbrf = ft_alloc(nbrf);
	ft_forward(nbr, &i, nbrf, &j);
	out = ft_conv(nbr, base_from, &i);
	j = (out == 0) ? 0 : j;
	ft_nbr_to(out, base_to, nbrf, &j);
	nbrf[j] = '\0';
	return (nbrf);
}
