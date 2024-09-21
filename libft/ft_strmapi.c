/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:36:20 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/09 16:36:20 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*dest;

	i = 0;
	len = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[len] != '\0')
	{
		len++;
	}
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

/*
char cambiar_letra(unsigned int indice, char c) {
    if (indice % 2 == 0) {
        return (c >= 'a' && c <= 'z') ? c - 32 : c;
    } else {
        return (c >= 'A' && c <= 'Z') ? c + 32 : c;
    }
}

int main() {
    char str[] = "Hola Mundo!";
    char *nueva_cadena = ft_strmapi(str, &cambiar_letra);
    
    printf("Cadena original: %s\n", str);
    printf("Nueva cadena: %s\n", nueva_cadena);
    
    free(nueva_cadena);
	return 0;
}
*/