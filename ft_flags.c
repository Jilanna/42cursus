/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:23:21 by nvu               #+#    #+#             */
/*   Updated: 2021/02/09 15:35:06 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_init(t_flags *flags)
{
	(*flags).minus = 0;
	(*flags).zero = 0;
	(*flags).width = -1;
	(*flags).precision = -2;
	(*flags).type = 'b';
}

int		ft_flags_star(int *j, const char *format, int *i, va_list ap)
{
	if (format[*i] == '*')
	{
		(*j) = va_arg(ap, int);
		(*i)++;
		return(*j);
	}
	return (0);
}

int		ft_flags_length(const char *format, int *i, va_list ap)
{
	int			j;
    char		*temp;

	if (ft_flags_star(&j, format, i, ap))
		return (j);
	j = -1;
	while ((++j >= 0) && (format[*i] >= '0') && (format[*i] <= '9'))
		(*i)++;
	if (j == 0)
		return (0);
	if (!(temp = malloc(sizeof(char) * (j + 1))))
		return (-1);
	(*i) = (*i) - j;
	j = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		temp[j] = format[*i];
		(*i)++;
		j++;
	}
	temp[j] = '\0';
	j = ft_atoi(temp);
	free(temp);
	return (j);
}

void	ft_imprflags(t_flags *flags)
{
	printf("minus:%i, zero:%i, width:%i, precision:%i, type:%c\n", flags->minus,
			flags->zero, flags->width, flags->precision, flags->type);	
}


int		ft_flags(t_flags *flags, const char *format, int *i, va_list ap)
{
	ft_flags_init(flags);
	if (format[*i] == '-')
		flags->minus = 1;
	else if (format[*i] == '0')
		flags->zero = 1;
	if ((flags->minus == 1 || flags->zero == 1))
		(*i)++;
	if ((flags->width = ft_flags_length(format, i, ap)) == -1)
		return (-1);
	if (format[*i] == '.')
	{
		(*i)++;
		printf("befpre:%c\n", format[*i]);
		if ((flags->precision = ft_flags_length(format, i, ap)) == -1)
			return (-1);
	}
	flags->type = format[*i];
	if ((flags->type != 'i') && (flags->type != 'd') && (flags->type != 'u')
		&& (flags->type != 'x') && (flags->type != 'X') && (flags->type != 'c')
		&& (flags->type != 's') && (flags->type != 'p')
		&& (flags->type != '%'))
		return (-1);
	ft_imprflags(flags);
	return (0);
}
