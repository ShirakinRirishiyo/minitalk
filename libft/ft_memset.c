/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:27:56 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/06 20:27:56 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int main() {
    char buffer[10]; // Un buffer de 10 bytes

    // Llenar el buffer con 'A's utilizando ft_memset
    ft_memset(buffer, 'A', sizeof(buffer));

    // Imprimir el contenido del buffer
    printf("Contenido del buffer: ");
    for (int i = 0; i < sizeof(buffer); i++) {
        printf("%c ", buffer[i]);
    }
    printf("\n");

    return 0;
}*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cptr;

	cptr = s;
	while (n-- > 0)
	{
		*cptr++ = c;
	}
	return (s);
}
