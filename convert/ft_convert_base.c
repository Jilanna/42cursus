/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:07:30 by nvu               #+#    #+#             */
/*   Updated: 2020/08/24 17:19:19 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int				ft_strlen_test(char *str);
void			ft_forward(char *nbr, unsigned long *i, char *nbrf,
		unsigned long *j);
int				ft_is_in_base(char c, char *base);
unsigned long	ft_savenbr(char c, char *base, unsigned long sortie);
char			*ft_alloc(char *nbrf);

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