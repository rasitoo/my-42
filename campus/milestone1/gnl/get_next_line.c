/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 13:47:10 by rtapiado          #+#    #+#             */
/*   Updated: 2026/11/22 16:42:11 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_error(char *stash, char *buf)
{
	free(stash);
	free(buf);
	return (NULL);
}

static char	*read_and_stash(int fd, char *stash)
{
	ssize_t	bytes_read;
	char	*buf;

	if (BUFFER_SIZE <= 0 || ft_strchr(stash, '\n'))
		return (stash);
	bytes_read = BUFFER_SIZE;
	buf = (char *)malloc(sizeof(char) * (bytes_read + 1));
	if (!buf)
		return (clean_error(stash, NULL));
	buf[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(buf, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (clean_error(stash, buf));
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (clean_error(NULL, buf));
	}
	free(buf);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	len;

	if (!stash || stash[0] == '\0')
		return (NULL);
	len = 0;
	while (stash[len] != '\n' && stash[len] != '\0')
		len++;
	if (stash[len] == '\n')
		len++;
	return (ft_substr(stash, 0, len));
}

static char	*update_stash(char *stash, char **line)
{
	char	*new_stash;
	size_t	len;
	size_t	n;

	len = ft_strlen(stash);
	n = 0;
	while (stash[n] != '\n' && stash[n] != '\0')
		n++;
	if (!stash[n] || !stash[n + 1])
		return (clean_error(stash, NULL));
	new_stash = ft_substr(stash, n + 1, len - n - 1);
	free(stash);
	if (!new_stash)
		*line = clean_error(*line, NULL);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = update_stash(stash, &line);
	return (line);
}
