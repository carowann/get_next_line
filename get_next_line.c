/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caroline <caroline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:20:48 by cwannhed          #+#    #+#             */
/*   Updated: 2024/12/10 23:00:35 by caroline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line_read;
	char		*temp;
	int			sz;
	size_t		line_len;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (stash == NULL || ft_strchr(stash, '\n') == NULL)
	{
		line_read = NULL;
		buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		sz = read(fd, buffer, BUFFER_SIZE);
		if (sz == 0)
		{
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
			free (buffer);
			free (stash);
			stash = NULL;
			return (NULL);
		}
		temp = stash;
		free(stash);
		stash = NULL;
		stash = ft_strjoin(stash, buffer);
		free(buffer);
	}
	line_len = ft_strchr(stash, '\n') - stash + 1;
	line_read = ft_strndup(stash, line_len);
	if (ft_strlen(stash) > line_len)
	{
		temp = ft_strndup(&stash[line_len], ft_strlen(stash) - line_len);
		free(stash);
		stash = temp;
	}
	else
	{
		free(stash);
		stash = NULL;
	}
	return (line_read);
}

int	main()
{
	int		fd;
	char	*line_read;

	line_read = NULL;
	fd = open("prova.txt", O_RDONLY);
	//fd = -1;
	printf( "fd = %d\n", fd);
	line_read = get_next_line(fd);
	printf("Line read is: %s", line_read);
	while (line_read != NULL)
	{
		free(line_read);
		line_read = get_next_line(fd);
		printf("Line read is: %s", line_read);
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