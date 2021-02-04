/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:34:49 by nvu               #+#    #+#             */
/*   Updated: 2021/02/03 10:08:46 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

void		ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_base(unsigned long long nbr, int base_len, char *base)
{
	if (nbr > (base_len - 1))
	{
		ft_putnbr_base(nbr / base_len, base_len, base);
		ft_putnbr_base(nbr % base_len, base_len, base);
	}
	else
		ft_putchar_fd(base[nbr], 1);
}

void		ft_putnbru(unsigned long long nbr, char type)
{
	if (type == 'u')
		ft_putnbr_base(nbr, 10, "0123456789");
	else if (type == 'x')
		ft_putnbr_base(nbr, 16, "0123456789abcdef");
	else if (type == 'X')
		ft_putnbr_base(nbr, 16, "0123456789ABCDEF");
}

