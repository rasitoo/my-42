/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:17:00 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 16:40:08 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		neg;
	long	res;
	int		idx;

	neg = 1;
	res = 0;
	idx = 0;
	while ((nptr[idx] >= 9 && nptr[idx] <= 13) || nptr[idx] == ' ')
		idx++;
	if (nptr[idx] == '-' || nptr[idx] == '+')
	{
		if (nptr[idx] == '-')
			neg = -1;
		idx++;
	}
	while (nptr[idx] >= '0' && nptr[idx] <= '9')
	{
		res = res * 10 + (nptr[idx] - '0');
		idx++;
	}
	return ((int)(res * neg));
}
