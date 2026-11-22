/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 17:47:00 by rtapiado          #+#    #+#             */
/*   Updated: 2026/11/22 17:47:00 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static void	read_fd(int fd, const char *source_name)
{
	char	*line;
	int		line_num;

	printf("--- Leyendo: %s ---\n", source_name);
	line_num = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("[%03d] %s", line_num, line);
		free(line);
		line = get_next_line(fd);
		line_num++;
	}
	printf("\n--- Fin de: %s (total: %d lineas) ---\n\n",
		source_name, line_num - 1);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc == 1)
		read_fd(0, "stdin");
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
				printf("Error: no se pudo abrir '%s'\n", argv[i]);
			else
			{
				read_fd(fd, argv[i]);
				close(fd);
			}
			i++;
		}
	}
	return (0);
}
