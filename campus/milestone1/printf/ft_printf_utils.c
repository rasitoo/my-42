/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:48:26 by rtapiado          #+#    #+#             */
/*   Updated: 2026/09/28 17:31:47 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long l)
{
	int		bytes;
	char	c;

	bytes = 0;
	c = 0;
	if (l < 0)
	{
		bytes += write(1, "-", 1);
		l = -l;
	}
	if (l >= 10)
		bytes += ft_putnbr(l / 10);
	c = (l % 10) + '0';
	bytes += write(1, &c, 1);
	return (bytes);
}

int	ft_putstr(char *s)
{
	size_t	idx;

	if (!s)
		s = "(null)";
	idx = 0;
	while (s[idx] != '\0')
		idx++;
	if (s != NULL)
		write(1, s, idx);
	return (idx);
}
