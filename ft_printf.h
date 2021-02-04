/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:34:59 by nvu               #+#    #+#             */
/*   Updated: 2021/02/04 12:27:33 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
typedef struct		s_flags
{
	int				minus;
	int				zero;
	int				width;
	int				precision;
	char			type;
}					t_flags;

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
int		ft_treatment(va_list ap, const char *format);
char	*ft_recup(t_flags *flags, va_list ap);
int		ft_printing(t_flags *flags, va_list ap);
void	ft_flags_init(t_flags *flags);
int		ft_flags_star(int *j, const char *format, int *i, va_list ap);
int		ft_flags_length(const char *format, int *i, va_list ap);
int		ft_flags(t_flags *flags, const char *format, int *i, va_list ap);
int		ft_print_nb(char *str, int len, t_flags *flags);
int		ft_print_str(char *str, int len, t_flags *flags);
int		ft_print_char(char *str, int len, t_flags *flags);
int		ft_print_ptr(char *str, int len, t_flags *flags);
int		ft_add_before(char *str, char c, int len, int to_add);
int		ft_add_after(char *str, char c, int width);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *str);
int		ft_atoi(char *str);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_itoa(int n);
char	*ft_ptrtoa(void *ptr);
char	*ft_utoa(unsigned int n, char type);
#endif
