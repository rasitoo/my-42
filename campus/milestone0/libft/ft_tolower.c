/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:52:52 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/13 23:04:38 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 65 && c <= 90))
		c = c + 32;
	return (c);
}

// int	main(void)
// {
// 	char	tests[] = {'a', 'z', 'm', 'A', 'Z', '5', '@', ' '};
// 	int		i;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		printf("Carácter original: '%c'\n", tests[i]);
// 		printf("ft_tolower: '%c'\n", ft_tolower(tests[i]));
// 		printf("tolower   : '%c'\n", tolower(tests[i]));

// 		if (ft_tolower(tests[i]) == tolower(tests[i]))
// 			printf("OK\n\n");
// 		else
// 			printf("ERROR\n\n");

// 		i++;
// 	}
// 	return (0);
// }
