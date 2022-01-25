/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_itoa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:30:01 by ctanton           #+#    #+#             */
/*   Updated: 2021/01/12 17:30:07 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	len_res(long int n)
{
	size_t		len;
	long int	pn;

	len = 0;
	pn = n;
	if (n < 0)
	{
		pn *= (-1);
		len++;
	}
	if (pn == 0)
		return (1);
	while (pn > 0)
	{
		pn /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long int n)
{
	char			*dst;
	long long int	pn;
	size_t			len;

	pn = (long int)n;
	len = len_res(pn);
	if (!(dst = (char *)malloc(len + 1)))
		return (NULL);
	dst[len--] = '\0';
	if (pn == 0)
		dst[0] = '0';
	if (pn < 0)
	{
		*dst = '-';
		pn *= (-1);
	}
	while (pn > 0)
	{
		dst[len--] = (pn % 10) + '0';
		pn /= 10;
	}
	return (dst);
}

size_t	len_res_xxbig(unsigned long int n)
{
	size_t				len;
	unsigned long int	pn;

	len = 0;
	pn = n;
	if (n < 0)
	{
		pn *= (-1);
		len++;
	}
	if (pn == 0)
		return (1);
	while (pn > 0)
	{
		pn /= 16;
		len++;
	}
	return (len);
}

char	*ft_itoa_xxbig(unsigned long int n, t_pars ptr)
{
	char				*dst;
	unsigned long int	pn;
	int					len;

	pn = (unsigned long int)n;
	len = len_res_xxbig(pn);
	if (!(dst = (char *)malloc(len + 1)))
		return (NULL);
	dst[len--] = '\0';
	if (pn == 0)
		dst[0] = '0';
	while (n > 0)
	{
		pn = n % 16;
		if (pn > 9 && ptr.x_or_xbig == 0)
			dst[len--] = pn - 9 + 96;
		else if (pn > 9 && ptr.x_or_xbig == 1)
			dst[len--] = pn - 9 + 64;
		else
			dst[len--] = pn + 48;
		n /= 16;
	}
	return (dst);
}
