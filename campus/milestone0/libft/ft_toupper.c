/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:53:03 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/13 23:04:48 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 97 && c <= 122))
		c = c - 32;
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
// 		printf("ft_toupper: '%c'\n", ft_toupper(tests[i]));
// 		printf("toupper   : '%c'\n", toupper(tests[i]));

// 		if (ft_toupper(tests[i]) == toupper(tests[i]))
// 			printf("OK\n\n");
// 		else
// 			printf("ERROR\n\n");

// 		i++;
// 	}
// 	return (0);
// }
