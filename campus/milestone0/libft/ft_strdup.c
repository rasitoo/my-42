/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:51:08 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by copilot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	/* Simple idea: duplicate a string into fresh memory. */
	len = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, len + 1);
	return (dup);
}

#ifdef FT_MAIN
int	main(void)
{
	char	*res;

	res = ft_strdup("abc");
	printf("strdup: %s\n", res);
	free(res);
	return (0);
}
#endif
