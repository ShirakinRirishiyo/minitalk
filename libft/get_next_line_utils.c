/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:29:16 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/06/14 12:29:16 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_gnl(const char *s1)
{
	size_t	len;
	char	*dest;
	char	*ptr;

	len = ft_strlen_gnl(s1);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	ptr = dest;
	while (*s1)
	{
		*dest++ = *s1++;
	}
	*dest = '\0';
	return (ptr);
}

/**
 * Concatenates two strings and frees the first one.
 */
char	*strjoin_and_free(char *s1, const char *s2)
{
	size_t		len1;
	size_t		len2;
	char		*result;

	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (free(s1), NULL);
	if (s1)
		ft_strlcpy_gnl(result, s1, len1 + 1);
	ft_strlcpy_gnl(&result[len1], s2, len2 + 1);
	return (free(s1), result);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)&s[i]);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen_gnl(src);
	if (srclen + 1 < dstsize)
	{
		ft_memcpy_gnl (dst, src, srclen);
		dst[srclen] = '\0';
	}
	else if (dstsize != 0)
	{
		ft_memcpy_gnl (dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}

void	*ft_memcpy_gnl(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (n--)
	{
		*pdst++ = *psrc++;
	}
	return (dst);
}
