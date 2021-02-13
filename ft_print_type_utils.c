/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:35:08 by nvu               #+#    #+#             */
/*   Updated: 2021/02/11 10:01:32 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_add_before(char *str, char c, int len, int to_add)
{
	char		*temp;
	int			i;

	if (!(temp = malloc(sizeof(char) * (len + to_add + 1))))
		return (-1);
	i = -1;
	printf("abcde\n");
	while (++i < to_add)
		temp[i] = c;
	printf("bcdef%i|%i\n", i, to_add);
	//printf("len|%i|\n", len);
	while (str[i - to_add])
	{
		//printf("temp=|%s|%i", temp, i);
		temp[i] = str[i - to_add];
		i++;
	}
	printf("cdefg\n");
	temp[i] = '\0';
	printf("defgh\n");
	free(str);
	str = temp;
	return (len + to_add);
}

int		ft_add_after(char *str, char c, int width)
{
	char		*temp;
	int			i;

	if (!(temp = malloc(sizeof(char) * (width))))
		return (-1);
	i = -1;
	while (str[++i])
		temp[i] = str[i];
	i--;
	while (++i < (width - 1))
		temp[i] = c;
	temp[i] = '\0';
	free(str);
	str = temp;
	return (width);
}
