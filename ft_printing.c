/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:28:29 by nvu               #+#    #+#             */
/*   Updated: 2021/02/25 09:45:54 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_special(char *str, t_flags *flags)
{
	if (flags->type != 's' && flags->type != 'p' && flags->type != 'c' 
		&& ft_strlen(str) == 1 && str[0] == '0' && flags->precision == 0)
	{
		free(str);
		if (!(str = malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}

char	*ft_recup(t_flags *flags, va_list ap)
{
	char			*str;

	if (flags->type == 'i' || flags->type == 'd')
		str = ft_itoa(va_arg(ap, int));
	else if (flags->type == 'u' || flags->type == 'x' || flags->type == 'X')
		str = ft_utoa(va_arg(ap, unsigned int), flags->type);
	else if (flags->type == 's')
		str = ft_strdup(va_arg(ap, char *));
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

char	*ft_callprints(t_flags *flags, va_list ap)
{
	int		len;
	char	*str;

	if ((str = ft_recup(flags, ap)) == NULL)
		return (NULL);
	len = (int)ft_strlen(str);
	if ((str = ft_special(str, flags)) == NULL)
		return (NULL);
	if ((flags->type == 'i') || (flags->type == 'd'))
		str = ft_print_nb(str, len, flags);
	else if ((flags->type == 'u') || (flags->type == 'x') || (flags->type == 'X'))
		str = ft_print_un(str, len, flags);
	else if (flags->type == 's')
		str = ft_print_str(str, len, flags);
	else if (flags->type == 'p')
		str = ft_print_ptr(str, len, flags);
	else
		str = ft_print_char(str, flags);
	return (str);
}

int		ft_printing(t_flags *flags, va_list ap)
{
	char	*str;
	int		len;

	if ((str = ft_callprints(flags, ap)) == NULL)
		return (-1);
	len = ft_strlen(str);
	if (flags->type != 'c')
		ft_putstr(str);
	else
	{
		len = -1;
		while (++len < flags->width)
			write(1, &str[len], 1);
		len = flags->width;
	}
//	printf("bef free\n");
	free(str);
//	printf("aft free\n");
	return (len);
}
