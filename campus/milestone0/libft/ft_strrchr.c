/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:36:10 by rtapiado          #+#    #+#             */
/*   Updated: 2026/06/27 16:36:16 by rtapiado         ###   ########.fr       */
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
