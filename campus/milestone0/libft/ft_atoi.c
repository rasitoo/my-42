/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:31:29 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		neg;
	long	res;
	int		idx;

	/* Correction: the parser must skip spaces and handle signs before converting. */
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

#ifdef FT_MAIN
int	main(void)
{
	printf("atoi: %d\n", ft_atoi("-42"));
	return (0);
}
#endif
