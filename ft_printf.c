/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:30:26 by ctanton           #+#    #+#             */
/*   Updated: 2021/01/12 17:30:27 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_pars	ad_struct(void)
{
	t_pars	ptr;

	ptr.flag = -1;
	ptr.width = -1;
	ptr.precision = -1;
	ptr.x_or_xbig = -1;
	ptr.lenstr = 0;
	ptr.i = 0;
	return (ptr);
}

int				ft_printf(const char *str, ...)
{
	t_pars	ptr;
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str != '%')
			len += ft_putchar(*str++);
		else
		{
			str++;
			ptr = ad_struct();
			ptr = ft_parsing_flags((char *)str, ptr, ap);
			str += ptr.lenstr;
			if ((len = ft_processor((char *)str, ap, ptr, len)) < 0)
				return (-1);
			str++;
		}
	}
	va_end(ap);
	return (len);
}
