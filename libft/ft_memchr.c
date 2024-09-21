/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:41:50 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/06 18:41:50 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	if (n != 0)
	{
		while (n-- != 0)
		{
			if (*ptr++ == (unsigned char)c)
				return ((void *)ptr - 1);
		}
	}
	return (NULL);
}

/*
int main() 
{
    char str[] = "Hello, world!";
    char *ptr;
    char ch = 'o';

    ptr = (char *)ft_memchr(str, ch, strlen(str));

    if (ptr != NULL) 
	{
        printf("'%c' encontrado en la posición %ld.\n", ch, ptr - str);
    } 
	else 
	{
        printf("'%c' no encontrado.\n", ch);
    }
    return (0);
}
*/
