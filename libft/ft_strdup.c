/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu </var/mail/nvu>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:54:18 by nvu               #+#    #+#             */
/*   Updated: 2021/02/25 10:06:47 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	size_t		i;
	size_t		src_len;

	if (!src)
	{
		if (!(ptr = malloc(sizeof(char) * 7)))
			return (NULL);
		ptr[0] = '(';
		ptr[1] = 'n';
		ptr[2] = 'u';
		ptr[3] = 'l';
		ptr[4] = 'l';
		ptr[5] = ')';
		ptr[6] = '\0';
		return (ptr);
	}
	src_len = ft_strlen(src);
	if (!(ptr = malloc(sizeof(char) * (src_len + 1))))
		return (NULL);
	i = -1;
	while (++i < src_len)
		ptr[i] = src[i];
	ptr[i] = '\0';
	return (ptr);
}
