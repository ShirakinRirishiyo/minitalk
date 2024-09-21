/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:34:48 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/11 11:13:51 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*ptr1 != *ptr2)
		{
			return (*ptr1 - *ptr2);
		}
		ptr1++;
		ptr2++;
	}
	return (0);
}

/* int main()
{
    char str1[] = "Hello";
    char str2[] = "Hellp";
    size_t n = 5; // número de bytes a comparar

    int resultado = ft_memcmp(str1, str2, n);
    if (resultado > 0)
    {
        printf("La cadena 1 es mayor que la cadena 2.\n");
    }
    else if (resultado < 0)
    {
        printf("La cadena 1 es menor que la cadena 2.\n");
    }
    else
    {
        printf("Las cadenas son iguales.\n");
    }

    return 0;
}
*/
