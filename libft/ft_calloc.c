/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:50:52 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/06 10:50:52 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (nmemb == 0 && size == 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	ptr = (char *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return ((void *)ptr);
}

/*int main()
{
    char *str;
    size_t i;

    str = (char *)ft_calloc(100, sizeof(char));
    if (str == NULL)
    {
        printf("Error: No se pudo asignar memoria\n");
        return (1);
    }
    printf("Valores de los elementos asignados:\n");
    for (i = 0; i < 100; i++)
    {
        printf("%d ", str[i]);
    }
    printf("\n");
    free(str);
    return (0);
}*/
