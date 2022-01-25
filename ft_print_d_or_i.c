/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_or_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:28:59 by ctanton           #+#    #+#             */
/*   Updated: 2021/01/12 17:29:01 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	put_space_or_zero(t_pars ptr, int len, int i, int flag)
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

int	put_negative_number(char *str, int i, t_pars ptr, int len)
{
	int flag;

	flag = 0;
	if (ptr.flag == 0)
		len += ft_putchar('-');
	str++;
	i--;
	ptr.width--;
	if (ptr.flag == 0)
		len = put_space_or_zero(ptr, len, i, 2);
	if (ptr.flag == 1)
		len += ft_putchar('-');
	if ((ptr.flag == -1 || ptr.flag == 1) && ptr.precision < i)
		ptr.precision = i;
	if (ptr.flag == -1)
	{
		len = put_space_or_zero(ptr, len, 0, 0);
		len += ft_putchar('-');
	}
	if (ptr.flag == 1 || ptr.flag == -1)
		len = put_space_or_zero(ptr, len, i, 1);
	len += ft_putstr(str);
	if (ptr.flag == 1)
		len = put_space_or_zero(ptr, len, 0, 0);
	return (len);
}

int	put_positive_number(char *str, int i, t_pars ptr, int len)
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

int	process_minus_or_zero_flag(char *str, int i, t_pars ptr, int n)
{
	int len;

	len = 0;
	if (ptr.flag == -1)
	{
		if (ptr.precision == 0 && n == 0)
			len = if_precision(ptr, len);
		else if (*str == '-')
			len = put_negative_number((char *)str, i, ptr, len);
		else
			len = put_positive_number((char *)str, i, ptr, len);
	}
	if (ptr.flag == 0)
	{
		if (ptr.precision == 0 && n == 0)
			ptr.precision = ptr.precision;
		else if (*str == '-')
			len = put_negative_number((char *)str, i, ptr, len);
		else
			len = put_positive_number((char *)str, i, ptr, len);
	}
	return (len);
}

int	ft_print_d_or_i(long int n, t_pars ptr)
{
	char	*str;
	char	*tmp;
	int		i;
	int		len;

	tmp = ft_itoa(n);
	str = tmp;
	i = ft_strlen(str);
	len = 0;
	if (ptr.flag == -1 || ptr.flag == 0)
		len = process_minus_or_zero_flag((char *)str, i, ptr, n);
	if (ptr.flag == 1)
	{
		if (ptr.precision == 0 && n == 0 && (ptr.width == -1 || ptr.width == 0))
			len = 0;
		else if (ptr.precision == 0 && n == 0 && ptr.width != -1)
			len = put_space_or_zero(ptr, len, 0, 3);
		else if (*str == '-')
			len = put_negative_number((char *)str, i, ptr, len);
		else
			len = put_positive_number((char *)str, i, ptr, len);
	}
	free(tmp);
	return (len);
}
