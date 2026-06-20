/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:31:29 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/20 19:13:31 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	res;
	int	i;

	neg = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -neg;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = 10 * res + (nptr[i] - '0');
		i++;
	}
	return (res * neg);
}

// int	main(void)
// {
// 	char	*tests[] = {
// 		"42",
// 		"-42",
// 		"+42",
// 		"    42",
// 		"\t\n\v\f\r 42",
// 		"0042",
// 		"-0042",
// 		"+++---++-+-+--++-++++--+-42abc",
// 		"abc42",
// 		"",
// 		"+",
// 		"-"
// 	};
// 	int	i;

// 	i = 0;
// 	while (i < 12)
// 	{
// 		printf("Entrada: \"%s\"\n", tests[i]);
// 		printf("ft_atoi: %d\n", ft_atoi(tests[i]));
// 		printf("atoi   : %d\n", atoi(tests[i]));

// 		if (ft_atoi(tests[i]) == atoi(tests[i]))
// 			printf("OK\n\n");
// 		else
// 			printf("ERROR\n\n");

// 		i++;
// 	}
// 	return (0);
// }
