/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:35:06 by nvu               #+#    #+#             */
/*   Updated: 2021/02/04 20:15:11 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			out;

	va_start(ap, format);
	ft_putchar_fd('w', 1);
	printf("beftreatment\n");
	out = ft_treatment(ap, format);
	printf("afttreatment\n");
	va_end(ap);
	return (out);
}

int		ft_treatment(va_list ap, const char *format)
{
	t_flags		*flags;
	int			out;
	int			i;

	printf("timawine");
	out = 0;
	i = -1;
	if (!(flags = malloc(sizeof(t_flags))))
		return (-1);
	while (format[++i] != '\0')
	{
		printf("la\n");
		if (format[i] == '%')
		{
			printf("avt flags\n");
			if (ft_flags(flags, format, &i, ap) == -1)
				return (-1);
			printf("avt printing\n");
			out += ft_printing(flags, ap);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			out++;
		}
	}
	return (out);
}