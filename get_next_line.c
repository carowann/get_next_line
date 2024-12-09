/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:20:48 by cwannhed          #+#    #+#             */
/*   Updated: 2024/12/09 19:36:34 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	char	*stash;
	char			*buffer;
	char			*line_read;
	char			*temp;
	int				sz;
	size_t			line_read_len;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (stash == NULL || ft_strchr(stash, '\n') == NULL)
	{
		line_read = NULL;
		buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
		if (!buffer)
			return (NULL);
		if (fd < 0)
			return (NULL);
		sz = read(fd, buffer, BUFFER_SIZE);
		if (sz == 0)
		{
			printf("sz: %d. No bytes read, EOF\n", sz);
			free(buffer);
			if (stash && *stash)
			{
				temp = stash;
				stash = NULL;
				return (temp);
			}
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (sz == -1)
		{
			printf("sz: %d. Error on read", sz);
			free (buffer);
			free (stash);
			stash = NULL;
			return (NULL);
		}
		buffer[sz] = '\0';
		stash = ft_strjoin(stash, buffer);
		free(buffer);
	}
	line_read_len = ft_strchr(stash, '\n') - stash + 1;
	line_read = ft_strndup(stash, line_read_len);
	stash = ft_strndup(&stash[line_read_len], ft_strlen(stash) - line_read_len + 1);
	return (line_read);
}

int	main()
{
	int		fd;
	char	*line_read;

	line_read = NULL;
	fd = open("prova.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error, fd < 0");
		return (1);
	}
	printf( "fd = %d\n", fd);
	line_read = get_next_line(fd);
	printf("Line read is: %s\n", line_read);
	while (line_read != NULL)
	{
		line_read = get_next_line(fd);
		printf("Line read is: %s\n", line_read);
	}
	if (close(fd) < 0)
	{
		printf("Error on close()");
		return (1);
	}
	printf ("closed fd");
	free(line_read);
	return (0);
}