/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu </var/mail/nvu>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:54:18 by nvu               #+#    #+#             */
/*   Updated: 2021/02/22 17:05:12 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	size_t		i;
	size_t		src_len;

	src_len = ft_strlen(src);
	if (!(ptr = malloc(sizeof(char) * (src_len + 1))))
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
