/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:30:34 by ctanton           #+#    #+#             */
/*   Updated: 2021/01/12 17:30:36 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_pars	ad_x_or_xbig_or_p(t_pars ptr, char *str)
{
	if (*str == 'x')
		ptr.x_or_xbig = 0;
	else if (*str == 'X')
		ptr.x_or_xbig = 1;
	if (*str == 'p')
		ptr.x_or_xbig = 0;
	return (ptr);
}

int				ft_processor(char *str, va_list ap, t_pars ptr, int len)
{
	ptr = ad_x_or_xbig_or_p(ptr, (char *)str);
	if (*str == 'd' || *str == 'i')
		return (len + ft_print_d_or_i(va_arg(ap, int), ptr));
	else if (*str == 's')
		return (len + ft_print_s(va_arg(ap, char *), ptr));
	else if (*str == 'c')
		return (len + ft_print_c(va_arg(ap, int), ptr));
	else if (*str == '%')
		return (len + ft_print_percent(ptr));
	else if (*str == 'x' || *str == 'X')
		return (len + ft_print_x_or_xbig(va_arg(ap, unsigned int), ptr));
	else if (*str == 'u')
		return (len + ft_print_u(va_arg(ap, unsigned int), ptr));
	else if (*str == 'p')
		return (len + ft_print_p(va_arg(ap, long long int), ptr));
	else
		return (-1);
}
