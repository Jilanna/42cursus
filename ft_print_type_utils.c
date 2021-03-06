/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:35:08 by nvu               #+#    #+#             */
/*   Updated: 2021/02/26 12:08:49 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_delminus(char *str)
{
	char		*new;
	int			i;

	if (str[0] != '-')
		return (str);
	if (!(new = malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	i = 1;
	while (str[i])
	{
		new[i - 1] = str[i];
		i++;
	}
	new[i - 1] = '\0';
	free(str);
	return (new);
}

char		*ft_add_before(char *str, char c, int len, int to_add)
{
	char		*temp;
	int			i;

	if (!(temp = malloc(sizeof(char) * (len + to_add + 1))))
		return (NULL);
	i = -1;
	while (++i < to_add)
		temp[i] = c;
	while ((i - to_add) < len)
	{
		temp[i] = str[i - to_add];
		i++;
	}
	temp[i] = '\0';
	free(str);
	return (temp);
}

char		*ft_add_after(char *str, char c, int len, int width)
{
	char		*temp;
	int			i;

	if (!(temp = malloc(sizeof(char) * (width + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		temp[i] = str[i];
	i--;
	while (++i < width)
		temp[i] = c;
	temp[i] = '\0';
	free(str);
	return (temp);
}
