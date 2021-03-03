/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:34:59 by nvu               #+#    #+#             */
/*   Updated: 2021/03/01 09:51:13 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			precision;
	char		type;
	int			other;
}				t_flags;

int				ft_printf(const char *format,
				...) __attribute__((format(printf,1,2)));
void			ft_putchar_fd(char c, int fd);
int				ft_treatment(va_list ap, const char *format);
char			*ft_recup(t_flags *flags, va_list ap);
char			*ft_callprints(t_flags *flags, va_list ap);
int				ft_printing(t_flags *flags, va_list ap);
void			ft_flags_init(t_flags *flags, const char *format, int *i);
int				ft_flags_star(int *j, int *i, va_list ap, t_flags *flags);
int				ft_flags_length(const char *f, int *i, va_list a, t_flags *fl);
int				ft_flags_neg(t_flags *flags);
int				ft_flags(t_flags *flags, const char *f, int *i, va_list ap);
char			*ft_print_nb(char *str, int len, t_flags *flags);
char			*ft_print_un(char *str, int len, t_flags *flags);
char			*ft_print_nb_width(char *str, int len, t_flags *flags);
char			*ft_print_str(char *str, int len, t_flags *flags);
char			*ft_print_char(char *str, t_flags *flags);
char			*ft_print_ptr(char *str, int len, t_flags *flags);
char			*ft_print_ptr2(char *temp, int len, t_flags *flags);
char			*ft_delminus(char *str);
char			*ft_add_before(char *str, char c, int len, int to_add);
char			*ft_add_after(char *str, char c, int len, int width);
void			ft_putstr(char *s);
size_t			ft_strlen(const char *str);
char			*ft_strdup(char *src);
int				ft_atoi(char *str);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
int				ft_strlen_test(char *str);
void			ft_forward(char *nbr, unsigned long *i, char *nbrf,
				unsigned long *j);
int				ft_is_in_base(char c, char *base);
unsigned long	ft_savenbr(char c, char *base, unsigned long sortie);
char			*ft_alloc(char *nbrf);
char			*ft_itoa(int n);
char			*ft_ptrtoa(void *ptr, t_flags *flags);
char			*ft_utoa(unsigned int n, char type);
#endif
