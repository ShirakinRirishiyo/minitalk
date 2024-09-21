/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:36:33 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/09 13:36:33 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int main() {
    // Ejemplo 1
    const char *cadena1 = "Hello, World!";
    unsigned int inicio1 = 7;
    size_t longitud1 = 5;

    char *resultado1 = ft_substr(cadena1, inicio1, longitud1);

    if (resultado1 != NULL) {
        printf("Cadena original: %s\n", cadena1);
        printf("Subcadena 1: %s\n", resultado1);

        free(resultado1); // Liberar la memoria asignada
    } 
	else 
	{
        printf("Error de asignación de memoria.\n");
    }
	return (0);
}
*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	i;
	char	*dest;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		len = 0;
	}
	else if (len > (str_len - start))
		len = str_len - start;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
