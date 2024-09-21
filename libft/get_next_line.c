/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:27:15 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/06/19 11:35:56 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t		i;

	if (!s || !s[0])
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * Duplicates a string up to a given length.
 */
static char	*process_line(const char *buffer, int length)
{
	char	*line;

	line = malloc(length + 1);
	if (!line)
		return (NULL);
	ft_strlcpy_gnl(line, buffer, length + 1);
	line[length] = '\0';
	return (line);
}

static ssize_t	read_and_append(int fd, char **result, char *buffer)
{
	ssize_t		bytes_read;

	bytes_read = 1;
	while (bytes_read != 0 && ft_strchr_gnl(*result, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (-1);
		buffer[bytes_read] = '\0';
		*result = strjoin_and_free(*result, buffer);
	}
	return (bytes_read);
}

static char	*process_and_update(char **result, ssize_t line_length)
{
	char	*line;
	char	*remaining;

	line = process_line(*result, line_length);
	if (!line)
		return (free(*result), NULL);
	remaining = ft_strdup_gnl(*result + line_length);
	free(*result);
	*result = remaining;
	return (line);
}

/**
 * Gets the next line from the file represented by fd.
 */
char	*get_next_line(int fd)
{
	static char		*result;
	char			*line;
	char			*buffer;
	ssize_t			read_result;

	if (BUFFER_SIZE <= 0 || fd < 0)
	return NULL;
		result = ft_strdup_gnl("");
	buffer = (char *)malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (buffer == NULL)
		return (NULL);
	read_result = read_and_append(fd, &result, buffer);
	free(buffer);
	if (read_result < 0 || ft_strlen_gnl(result) == 0)
		return (free(result), result = NULL, NULL);
	if (!ft_strchr_gnl(result, '\n'))
	{
		line = ft_strdup_gnl(result);
		return (free(result), result = NULL, line);
	}
	read_result = ft_strchr_gnl(result, '\n') - result;
	line = process_and_update(&result, read_result + 1);
	return (line);
}