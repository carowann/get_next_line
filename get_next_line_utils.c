/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:29:06 by cwannhed          #+#    #+#             */
/*   Updated: 2024/12/15 21:38:09 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*array;
	unsigned char	*uns_array;
	size_t			i;

	i = 0;
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	uns_array = (unsigned char *)array;
	while (i < nmemb * size)
	{
		*uns_array = '\0';
		uns_array++;
		i++;
	}
	return (array);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char *)ft_calloc(n + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	if (!s)
		return (NULL);
	chr = (unsigned char)c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		return ((ft_strndup(s2, ft_strlen(s2))));
	if (!s2)
		return (ft_strndup(s1, ft_strlen(s1)));
	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}
