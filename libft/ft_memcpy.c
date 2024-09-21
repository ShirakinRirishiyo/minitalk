/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:54:43 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/06 19:54:43 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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

/*
int main()
{
	char src[] = "Hello World!"; 
	char dest[50];
	ft_memcpy(dest, src, sizeof(src));
	printf("La cadena resultante es: %s\n", dest);
	return (0);
}
*/
