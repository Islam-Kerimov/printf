/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:29:32 by ctanton           #+#    #+#             */
/*   Updated: 2021/01/12 17:29:34 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	put_space_or_zero(t_pars ptr, int i, int len, int flag)
{
	while (ptr.width > i && flag == 0)
	{
		len += ft_putchar(' ');
		ptr.width--;
	}
	while (ptr.width > ptr.precision && flag == 1)
	{
		len += ft_putchar(' ');
		ptr.width--;
	}
	return (len);
}

static int	if_precision_not_i(t_pars ptr, int i)
{
	if (ptr.precision < i && ptr.precision > -1)
		i = ptr.precision;
	return (i);
}

static int	process_minus_flag(t_pars ptr, int i, int j, char *tmp)
{
	int len;

	len = 0;
	if (ptr.precision == 0)
		len = put_space_or_zero(ptr, i, len, 1);
	else if (ptr.precision < i && ptr.precision > -1 && ptr.width == -1)
	{
		while (j != ptr.precision)
			len += ft_putchar(tmp[j++]);
	}
	else
	{
		i = if_precision_not_i(ptr, i);
		len = put_space_or_zero(ptr, i, len, 0);
		while (ptr.precision > i)
			ptr.precision--;
		if (ptr.precision == i)
		{
			while (j != ptr.precision)
				len += ft_putchar(tmp[j++]);
		}
		else
			len += ft_putstr(tmp);
	}
	return (len);
}

static int	process_flag_one_or_zero(t_pars ptr, int i, int j, char *tmp)
{
	int len;

	len = 0;
	if (ptr.flag == 0)
	{
		len = put_space_or_zero(ptr, i, len, 0);
		len += ft_putstr(tmp);
	}
	if (ptr.flag == 1)
	{
		if (ptr.precision < i && ptr.precision > -1)
		{
			while (j != ptr.precision)
				len += ft_putchar(tmp[j++]);
			i = ptr.precision;
		}
		else
			len += ft_putstr(tmp);
		len = put_space_or_zero(ptr, i, len, 0);
	}
	return (len);
}

int			ft_print_s(char *str, t_pars ptr)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	j = 0;
	if (str == NULL)
		str = "(null)";
	tmp = str;
	i = ft_strlen(tmp);
	len = 0;
	if (ptr.flag == -1)
		len = process_minus_flag(ptr, i, j, tmp);
	if (ptr.flag == 0 || ptr.flag == 1)
		len = process_flag_one_or_zero(ptr, i, len, tmp);
	return (len);
}
