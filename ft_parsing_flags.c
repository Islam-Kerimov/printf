/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:28:48 by ctanton           #+#    #+#             */
/*   Updated: 2021/01/12 17:39:49 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_pars	pars_flags(char *str, t_pars ptr)
{
	int tmp;
	int tmp2;

	tmp = 0;
	tmp2 = 0;
	while (*str == '-' || *str == '0')
	{
		if (*str == '0')
		{
			ptr.flag = 0;
			tmp = 1;
		}
		else if (*str == '-')
		{
			ptr.flag = 1;
			tmp2 = 1;
		}
		if (tmp == 1 && tmp2 == 1)
			ptr.flag = 1;
		str++;
		ptr.i++;
	}
	return (ptr);
}

static	t_pars	pars_width(char *str, t_pars ptr, va_list ap)
{
	int tmp;

	tmp = 0;
	if (*str == '*')
	{
		ptr.width = va_arg(ap, int);
		if (ptr.width < 0)
		{
			ptr.flag = 1;
			ptr.width *= (-1);
		}
		str++;
		ptr.i++;
	}
	while (*str >= '0' && *str <= '9')
	{
		tmp = tmp * 10 + (*str - '0');
		ptr.width = tmp;
		str++;
		ptr.i++;
	}
	return (ptr);
}

static t_pars	pars_dotstar(char *str, t_pars ptr, va_list ap)
{
	if (*str == '*')
	{
		ptr.precision = va_arg(ap, int);
		ptr.i++;
	}
	return (ptr);
}

static t_pars	pars_precision(char *str, t_pars ptr, va_list ap)
{
	int tmp;

	tmp = 0;
	if (*str == '.')
	{
		str++;
		ptr.i++;
		if (*str != '*' && !(*str >= '0' && *str <= '9'))
			ptr.precision = 0;
		ptr = pars_dotstar((char *)str, ptr, ap);
		while (*str >= '0' && *str <= '9')
		{
			tmp = tmp * 10 + (*str - '0');
			ptr.precision = tmp;
			str++;
			ptr.i++;
		}
		if (ptr.precision > -1 && ptr.flag == 0)
			ptr.flag = -1;
		else if (ptr.precision < -1 && ptr.flag == -1)
			ptr.flag = -1;
	}
	return (ptr);
}

t_pars			ft_parsing_flags(char *str, t_pars ptr, va_list ap)
{
	ptr = pars_flags((char *)str, ptr);
	ptr.lenstr += ptr.i;
	str += ptr.i;
	ptr.i = 0;
	ptr = pars_width((char *)str, ptr, ap);
	ptr.lenstr += ptr.i;
	str += ptr.i;
	ptr.i = 0;
	ptr = pars_precision((char *)str, ptr, ap);
	ptr.lenstr += ptr.i;
	str += ptr.i;
	return (ptr);
}
