/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:31:29 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (s1[idx] != s2[idx])
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		if (s1[idx] == '\0')
			return (0);
		idx++;
	}
	return (0);
}

#ifdef FT_MAIN
int	main(void)
{
	printf("strncmp: %d\n", ft_strncmp("ab", "ac", 2));
	return (0);
}
#endif
