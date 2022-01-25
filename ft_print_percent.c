/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:29:22 by ctanton           #+#    #+#             */
/*   Updated: 2021/01/12 17:29:23 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	put_space_or_zero(t_pars ptr, int len, int i)
{
	while (ptr.width > i)
	{
		if (ptr.flag == 1 || ptr.flag == -1)
			len += ft_putchar(' ');
		else
			len += ft_putchar('0');
		ptr.width--;
	}
	return (len);
}

int			ft_print_percent(t_pars ptr)
{
	int		len;
	int		i;

	len = 0;
	i = 1;
	if (ptr.width == -1)
		len += ft_putchar('%');
	else if (ptr.flag == -1)
	{
		len = put_space_or_zero(ptr, len, i);
		len += ft_putchar('%');
	}
	else if (ptr.flag == 1)
	{
		len += ft_putchar('%');
		len = put_space_or_zero(ptr, len, i);
	}
	else if (ptr.flag == 0)
	{
		len = put_space_or_zero(ptr, len, i);
		len += ft_putchar('%');
	}
	return (len);
}
