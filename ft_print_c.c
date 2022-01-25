/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:26:32 by ctanton           #+#    #+#             */
/*   Updated: 2021/01/12 17:26:34 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_c(int c, t_pars ptr)
{
	int	len;
	int	i;

	len = 0;
	i = 1;
	if (ptr.flag == -1)
	{
		while (ptr.width > i)
		{
			len += ft_putchar(' ');
			ptr.width--;
		}
		len += ft_putchar(c);
	}
	if (ptr.flag == 1)
	{
		len += ft_putchar(c);
		while (ptr.width > i)
		{
			len += ft_putchar(' ');
			ptr.width--;
		}
	}
	return (len);
}
