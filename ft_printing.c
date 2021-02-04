/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:28:29 by nvu               #+#    #+#             */
/*   Updated: 2021/02/03 11:25:30 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_recup(t_flags *flags, va_list ap)
{
	char			*str;

	if (flags->type == 'i' || flags->type == 'd')
		str = ft_itoa(va_arg(ap, int));
	else if (flags->type == 'u' || flags->type == 'x' || flags->type == 'X')
		str = ft_utoa(va_arg(ap, unsigned int), flags->type);
	else if (flags->type == 's')
		str = (va_arg(ap, char *));
	else if (flags->type == 'p')
		str = ft_ptrtoa(va_arg(ap, void *));
	else
	{
		if (!(str = malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = '%';
		str[1] = '\0';
		if (flags->type == 'c')
			str[0] = va_arg(ap, int);
	}
	return (str);
}

int		ft_printing(t_flags *flags, va_list ap)
{
	int		len;
	char	*str;

	if ((str = ft_recup(flags, ap)) == NULL)
		return (-1);
	len = ft_strlen(str);
	if ((flags->type == 'i') || (flags->type == 'd') || (flags->type == 'u')
		|| (flags->type == 'x') || (flags->type == 'X'))
		len = ft_print_nb(str, len, flags);
	else if (flags->type == 's')
		len = ft_print_str(str, len, flags);
	else if (flags->type == 'p')
		len = ft_print_ptr(str, len, flags);
	else
		len = ft_print_char(str, len, flags);
	ft_putstr(str);
	return (len);
}