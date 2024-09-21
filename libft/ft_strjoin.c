/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:42:33 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/09 12:42:33 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int main() {
    const char *Pega = "Hola, ";
    const char *Copia = "Chirakin!";

    // Llamada a la función ft_strjoin
    char *subcadena = ft_strjoin(Pega, Copia);

    if (subcadena != NULL)
     {
        printf("Cadena resultante: %s\n", subcadena);

        // Liberar la memoria asignada
        free(subcadena);
    } else {
        fprintf(stderr, "Error.\n");
    }

    return 0;
}*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	len_s1;
	size_t	len_s2;
	char	*subcadena;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	subcadena = (char *)malloc(sizeof(char) * (total_len + 1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (subcadena != NULL)
	{
		ft_memcpy(subcadena, s1, len_s1);
		ft_memcpy(subcadena + len_s1, s2, len_s2);
		subcadena[total_len] = '\0';
		return (subcadena);
	}
	else
	{
		return (NULL);
	}
}
