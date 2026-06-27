/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:20:21 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 17:11:47 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	ln;
	int		len;
	int		idx;

	ln = n;
	len = ft_numlen(ln);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	idx = len - 1;
	if (ln < 0)
	{
		res[0] = '-';
		ln = -ln;
	}
	while (idx >= 0 && res[idx] != '-')
	{
		res[idx] = '0' + (ln % 10);
		ln /= 10;
		idx--;
	}
	return (res);
}
