/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:29:15 by ctanton           #+#    #+#             */
/*   Updated: 2021/01/12 17:29:16 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	put_space_or_zero(t_pars ptr, int i, int len, int flag)
{
	while (ptr.width > 0 && flag == 0)
	{
		len += ft_putchar(' ');
		ptr.width--;
	}
	while (ptr.precision > i && flag == 1)
	{
		len += ft_putchar('0');
		i++;
	}
	while (ptr.width > i && flag == 2)
	{
		len += ft_putchar(' ');
		ptr.width--;
	}
	return (len);
}

static int	put_space(t_pars ptr, int i, int len)
{
	if (ptr.width > i)
	{
		while (ptr.width != 0)
		{
			len += ft_putchar(' ');
			ptr.width--;
		}
	}
	return (len);
}

static int	process_minus_flag(t_pars ptr, char *str, long long int n, int i)
{
	int len;

	len = 0;
	if (ptr.precision == 0 && n == 0)
	{
		ptr.width = ptr.width - 2;
		len = put_space(ptr, i, len);
		len += ft_putstr("0x");
	}
	else
	{
		if (ptr.precision < i)
			ptr.precision = i;
		ptr.width = ptr.width - 2;
		while (ptr.width > ptr.precision)
		{
			len += ft_putchar(' ');
			ptr.width--;
		}
		len += ft_putstr("0x");
		len = put_space_or_zero(ptr, i, len, 1);
		len += ft_putstr(str);
	}
	return (len);
}

static int	process_flag_one(t_pars ptr, char *str, long long int n, int i)
{
	int len;

	len = 0;
	if (ptr.precision == 0 && n == 0 && ptr.width != -1)
		len = put_space_or_zero(ptr, 0, len, 0);
	else
	{
		len += ft_putstr("0x");
		len = put_space_or_zero(ptr, i, len, 1);
		len += ft_putstr(str);
		ptr.width = ptr.width - 2;
		len = put_space_or_zero(ptr, i, len, 2);
	}
	return (len);
}

int			ft_print_p(long long int n, t_pars ptr)
{
	char	*str;
	char	*tmp;
	int		len;
	int		i;

	len = 0;
	tmp = ft_itoa_xxbig(n, ptr);
	str = tmp;
	i = ft_strlen(str);
	if (ptr.flag == -1)
		len = process_minus_flag(ptr, (char *)str, n, i);
	if (ptr.flag == 1)
		len = process_flag_one(ptr, (char *)str, n, i);
	free(tmp);
	return (len);
}
