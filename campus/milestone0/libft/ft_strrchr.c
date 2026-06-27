/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:31:29 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;
	char	*res;

	res = NULL;
	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == (char)c)
			res = (char *)&s[idx];
		idx++;
	}
	if (c == '\0')
		return ((char *)&s[idx]);
	return (res);
}

#ifdef FT_MAIN
int	main(void)
{
	printf("strrchr: %s\n", ft_strrchr("banana", 'a'));
	return (0);
}
#endif
