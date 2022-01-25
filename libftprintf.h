/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:30:42 by ctanton           #+#    #+#             */
/*   Updated: 2021/01/12 17:30:43 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_pars
{
	int			flag;
	int			width;
	int			precision;
	int			x_or_xbig;
	int			lenstr;
	int			i;
}				t_pars;

int				ft_printf(const char *str, ...);
size_t			len_res(long int n);
char			*ft_itoa(long int n);
size_t			len_res_xxbig(unsigned long int n);
char			*ft_itoa_xxbig(unsigned long int n, t_pars ptr);
int				ft_putstr(char *s);
int				ft_putchar(char c);
int				ft_strlen(const char *s);
int				if_precision(t_pars ptr, int len);
int				ft_processor(char *str, va_list ap, t_pars ptr, int len);
int				ft_print_x_or_xbig(unsigned int n, t_pars ptr);
int				ft_print_u(unsigned int n, t_pars ptr);
int				ft_print_d_or_i(long int n, t_pars ptr);
int				ft_print_percent(t_pars ptr);
int				ft_print_c(int c, t_pars ptr);
int				ft_print_s(char *str, t_pars ptr);
int				ft_print_p(long long int n, t_pars ptr);
t_pars			ft_parsing_flags(char *str, t_pars ptr, va_list ap);

#endif
