/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_or_xbig.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:54:21 by ctanton           #+#    #+#             */
/*   Updated: 2021/01/12 17:54:22 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	put_space_or_zero(t_pars ptr, int len, int i, int flag)
{
	while (ptr.width > ptr.precision && flag == 0)
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
		if (ptr.flag == 1)
			len += ft_putchar(' ');
		else
			len += ft_putchar('0');
		ptr.width--;
	}
	while (ptr.width != 0 && flag == 3)
	{
		len += ft_putchar(' ');
		ptr.width--;
	}
	return (len);
}

static int	put_positive_number(char *str, int i, t_pars ptr, int len)
{
	if (ptr.flag == 1)
	{
		while (ptr.precision > i)
		{
			len += ft_putchar('0');
			i++;
		}
		len += ft_putstr(str);
		len = put_space_or_zero(ptr, len, i, 2);
	}
	if (ptr.flag == -1)
	{
		if (ptr.precision < i)
			ptr.precision = i;
		len = put_space_or_zero(ptr, len, 0, 0);
		len = put_space_or_zero(ptr, len, i, 1);
		len += ft_putstr(str);
	}
	if (ptr.flag == 0)
	{
		len = put_space_or_zero(ptr, len, i, 2);
		len = put_space_or_zero(ptr, len, i, 1);
		len += ft_putstr(str);
	}
	return (len);
}

static int	process_minus_or_zero(char *str, int i, t_pars ptr, unsigned int n)
{
	int len;

	len = 0;
	if (ptr.flag == -1)
	{
		if (ptr.precision == 0 && n == 0 && ptr.width > 0)
			len = put_space_or_zero(ptr, len, 0, 3);
		else if (ptr.precision == 0 && n == 0)
			len = 0;
		else
			len = put_positive_number((char *)str, i, ptr, len);
	}
	if (ptr.flag == 0)
	{
		if (ptr.precision == 0 && n == 0)
			ptr.precision = ptr.precision;
		else
			len = put_positive_number((char *)str, i, ptr, len);
	}
	return (len);
}

static int	process_flag_one(char *str, int i, t_pars ptr, unsigned int n)
{
	int len;

	len = 0;
	if (ptr.precision == 0 && n == 0 && (ptr.width == -1 || ptr.width == 0))
		len = 0;
	else if (ptr.precision == 0 && n == 0 && ptr.width != -1)
		len = put_space_or_zero(ptr, len, 0, 3);
	else
		len = put_positive_number((char *)str, i, ptr, len);
	return (len);
}

int			ft_print_x_or_xbig(unsigned int n, t_pars ptr)
{
	char	*str;
	char	*tmp;
	int		i;
	int		len;

	tmp = ft_itoa_xxbig(n, ptr);
	str = tmp;
	i = ft_strlen(str);
	len = 0;
	if (ptr.flag == -1 || ptr.flag == 0)
		len = process_minus_or_zero((char *)str, i, ptr, n);
	if (ptr.flag == 1)
		len = process_flag_one((char *)str, i, ptr, n);
	free(tmp);
	return (len);
}
