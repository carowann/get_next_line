/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:20:48 by cwannhed          #+#    #+#             */
/*   Updated: 2024/12/06 18:48:02 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	
	
	if (fd < 0)
		return (NULL);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*buffer;
	int		sz;
	
	fd = open("prova.txt", O_RDONLY);
	buffer = (char *)ft_calloc(100, sizeof(char));
	if (!buffer)
		return (1);
	if (fd < 0)
	{
		printf("Error, fd < 0");
		return (1);
	}
	printf( "fd = %d\n", fd);
	sz = read(fd, buffer, 15);
	printf("called read(% d, buffer, 10). Returned that %d bytes were read.\n", fd, sz);
	if (close(fd) < 0)
	{
		printf("Error on close()");
		return (1);
	}
	buffer[sz] = '\0';
	printf ("Those bytes are as follows: %s/fine buffer\n", buffer);
	printf ("closed fd");
	free (buffer);
	return (0);
}