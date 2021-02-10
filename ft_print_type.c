/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:35:10 by nvu               #+#    #+#             */
/*   Updated: 2021/02/10 19:47:37 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_nb(char *str, int len, t_flags *flags)
{
	if (flags->precision > len)
		if ((len = ft_add_before(str, '0', len, flags->precision - len)) == -1)
			return (-1);
	printf("yo\n");
	if (flags->width > len)
	{
		if (flags->minus == 1)
			len = ft_add_after(str, ' ', flags->width);
		else if ((flags->zero == 0) || (flags->zero == 1 
			&& flags->precision != -1))
		{
			len = ft_add_before(str, ' ', len, (flags->width) - len);
			printf("rftyui\n");
		}
		else
			len = ft_add_before(str, '0', len, flags->width - len);
	}
	printf("coucou\n");
	return (len);
}

int		ft_print_str(char *str, int len, t_flags *flags)
{
	if (flags->precision < len && flags->precision != -1)
	{
		str[flags->precision] = '\n';
		len = flags->precision;
	}
	if (flags->width > len)
	{
		if (flags->minus == 1)
			len = ft_add_after(str, ' ', flags->width);
		else
			len = ft_add_before(str, ' ', len, flags->width - len);
	}
	return (len);
}

int		ft_print_char(char *str, int len, t_flags *flags)
{
	if (flags->width > 1)
	{
		if (flags->minus == 1)
			len = ft_add_after(str, ' ', flags->width);
		else
			len = ft_add_before(str, ' ', 1, flags->width - 1);
	}
	return (len);
}

int		ft_print_ptr(char *str, int len, t_flags *flags)
{
	char		*temp;
	int			n;

	if (flags->precision > len)
		if ((len = ft_add_before(str, '0', len, flags->precision - len)) == -1)
			return (-1);
	if (!(temp = malloc(sizeof(char) * (len + 3))))
		return (-1);
	str[0] = '0';
	str[1] = 'x';
	n = 1;
	while (++n && str[n - 2])
		temp[n] = str[n - 2];
	temp[n] = '\0';
	free(str);
	len += 2;
	if (flags->width > len)
	{
		if (flags->minus == 1)
			len = ft_add_after(str, ' ', flags->width);
		else if ((flags->zero == 0)
			|| (flags->zero == 1 && flags->precision != -1))
			len = ft_add_before(str, ' ', len, flags->width - len);
		else
			len = ft_add_before(str, '0', len, flags->width - len);
	}
	return (len);
}
