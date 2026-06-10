/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:48:30 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/10 19:00:28 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	tests[] = {-1, 0, 65, 97, 127, 128, 255};
// 	int	i;

// 	i = 0;
// 	while (i < 7)
// 	{
// 		printf("Valor: %d\n", tests[i]);
// 		printf("ft_isascii: %d\n", ft_isascii(tests[i]) != 0);
// 		printf("isascii   : %d\n", isascii(tests[i]) != 0);

// 		if ((ft_isascii(tests[i]) != 0)
// 			== (isascii(tests[i]) != 0))
// 			printf("OK\n\n");
// 		else
// 			printf("ERROR\n\n");

// 		i++;
// 	}
// 	return (0);
// }
