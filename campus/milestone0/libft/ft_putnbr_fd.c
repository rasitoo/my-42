/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:50:44 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

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
	/* Simple idea: write an integer to a file descriptor. */
	ft_putnbr_recursive((long)n, fd);
}

#ifdef FT_MAIN
int	main(void)
{
	ft_putnbr_fd(42, 1);
	return (0);
}
#endif
