/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:48:46 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/10 19:02:36 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	tests[] = {31, 32, 65, 126, 127, '\n', '\t'};
// 	int	i;

// 	i = 0;
// 	while (i < 7)
// 	{
// 		printf("Valor: %d\n", tests[i]);
// 		printf("ft_isprint: %d\n", ft_isprint(tests[i]) != 0);
// 		printf("isprint   : %d\n", isprint(tests[i]) != 0);

// 		if ((ft_isprint(tests[i]) != 0)
// 			== (isprint(tests[i]) != 0))
// 			printf("OK\n\n");
// 		else
// 			printf("ERROR\n\n");

// 		i++;
// 	}
// 	return (0);
// }