/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:15:45 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/09 13:15:45 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if ((!dst || !src) && dstsize == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	if (dstsize > i)
	{
		while ((j + i + 1) < dstsize && src[j] != '\0')
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
		return (i + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}

/*
int main() {
    char destination[20] = "Hello, ";
    const char *source = "world!";

    size_t original_length = strlen(destination);
    size_t dest_size = sizeof(destination);
    size_t result_length = ft_strlcat(destination, source, dest_size);

    printf("Cadena concatenada: %s\n", destination);
    printf("Longitud original de la cadena de destino: %zu\n", original_length);
    printf("Longitud de la cadena de origen: %zu\n", strlen(source));
    printf("Longitud total de la cadena concatenada: %zu\n", result_length);

    return 0;
}*/