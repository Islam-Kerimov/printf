/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:30:15 by ctanton           #+#    #+#             */
/*   Updated: 2021/01/12 17:30:16 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *s)
{
	int i;
	int len;

	len = 0;
	if (s == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		len++;
	}
	return (len);
}

int	ft_putchar(char c)
{
	int len;

	len = 1;
	if (c || c == '\0')
		write(1, &c, 1);
	return (len);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	if_precision(t_pars ptr, int len)
{
	if (ptr.width > 0)
	{
		while (ptr.width != 0)
		{
			len += ft_putchar(' ');
			ptr.width--;
		}
	}
	else
		len = 0;
	return (len);
}
