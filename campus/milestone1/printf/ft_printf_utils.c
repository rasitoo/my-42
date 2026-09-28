/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:48:26 by rtapiado          #+#    #+#             */
/*   Updated: 2026/09/28 02:24:56 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	char	buffer[12];
	int		i;
	long	n;

	if (nb == 0)
		return (write(1, "0", 1));
	n = nb;
	nb = 0;
	if (n < 0)
	{
		nb = write(1, "-", 1);
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	nb += i;
	while (--i >= 0)
		write(1, &buffer[i], 1);
	return (nb);
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
