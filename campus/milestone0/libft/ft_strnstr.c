/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:31:29 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	jdx;

	if (*little == '\0')
		return ((char *)big);
	idx = 0;
	while (big[idx] != '\0' && idx < len)
	{
		jdx = 0;
		while (little[jdx] != '\0' && big[idx + jdx] == little[jdx] \
			&& idx + jdx < len)
			jdx++;
		if (little[jdx] == '\0')
			return ((char *)&big[idx]);
		idx++;
	}
	return (NULL);
}

#ifdef FT_MAIN
int	main(void)
{
	printf("strnstr: %s\n", ft_strnstr("hello", "ell", 5));
	return (0);
}
#endif
