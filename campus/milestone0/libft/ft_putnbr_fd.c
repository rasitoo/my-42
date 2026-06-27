/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:31:48 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 16:32:15 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recursive(long n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_recursive(n / 10, fd);
		ft_putnbr_recursive(n % 10, fd);
		return ;
	}
	write(fd, &(char){'0' + n}, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr_recursive((long)n, fd);
}
