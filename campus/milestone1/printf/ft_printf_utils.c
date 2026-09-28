/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:48:26 by rtapiado          #+#    #+#             */
/*   Updated: 2026/09/28 20:45:24 by rtapiado         ###   ########.fr       */
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

int	ft_puthex(unsigned long l, int uppercase)
{
	int		bytes;
	char	c;
	char	*hex;

	bytes = 0;
	c = 0;
	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (l >= 16)
		bytes += ft_puthex(l / 16, uppercase);
	c = hex[(l % 16)];
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

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putptr(void *p)
{
	if (!p)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_puthex((unsigned long)p, 0) + 2);
}
