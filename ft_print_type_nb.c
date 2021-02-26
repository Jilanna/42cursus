/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:35:10 by nvu               #+#    #+#             */
/*   Updated: 2021/02/26 12:19:14 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_nb_width(char *str, int len, t_flags *flags)
{
	if (flags->width > len)
	{
		if (flags->minus == 1)
			str = ft_add_after(str, ' ', len, flags->width);
		else if ((flags->zero == 0) || (flags->zero == 1 
			&& flags->precision != -2))
			str = ft_add_before(str, ' ', len, (flags->width) - len);
		else
		{
			if (flags->other == 1)
				len += 1;
			if ((str = ft_add_before(str, '0', len, flags->width - len)) == NULL)
				return (NULL);
			if (flags->other == 1)
				str = ft_add_before(str, '-', ft_strlen(str), 1);
		}
	}
	return (str);
}

char	*ft_print_nb(char *str, int len, t_flags *flags)
{
	if (str[0] == '-')
	{
		flags->other = 1;
		if (flags->precision != -2)
			flags->precision += 1;
	}
	str = ft_delminus(str);
	if (flags->precision > len)
	{
		if ((str = ft_add_before(str, '0', len, flags->precision - len)) == NULL)
			return (NULL);
	}
	if (flags->other == 1 && (flags->width <= len || (flags->minus == 1 || ((flags->zero == 0) || (flags->zero == 1 
			&& flags->precision != -2)))))
		if ((str = ft_add_before(str, '-', ft_strlen(str), 1)) == NULL)
			return (NULL);
	str = ft_print_nb_width(str, ft_strlen(str), flags);
	return (str);
}

char	*ft_print_un(char *str, int len, t_flags *flags)
{
//	printf("bef print\n");
	if (flags->precision > len)
	{
		if ((str = ft_add_before(str, '0', len, flags->precision - len)) == NULL)
			return (NULL);
	}
//	printf("aft precision\n");
	str = ft_print_nb_width(str, ft_strlen(str), flags);
	return (str);
}
