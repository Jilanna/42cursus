/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:35:06 by nvu               #+#    #+#             */
/*   Updated: 2021/02/09 15:36:18 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		bob(const char *format, ...)
{
	va_list		ap;
	int			out;

	va_start(ap, format);
	//printf("beftreatment\n");
	out = ft_treatment(ap, format);
	//printf("afttreatment\n");
	va_end(ap);
	return (out);
}

int		ft_treatment(va_list ap, const char *format)
{
	t_flags		*flags;
	int			out;
	int			i;

	out = 0;
	i = -1;
	if (!(flags = malloc(sizeof(t_flags))))
		return (-1);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			//printf("avt flags%i\n", out);
			if (ft_flags(flags, format, &i, ap) == -1)
				return (-1);
			//printf("avt printing, out = |%i|%i|\n", out, i);
			out += ft_printing(flags, ap);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			out++;
		}
	}
	free(flags);
	flags = NULL;
	return (out);
}
