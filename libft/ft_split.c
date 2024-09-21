/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:14:05 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/23 14:06:30 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	*ft_copyword(const char *start, size_t len)
{
	char	*word;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_memcpy(word, start, len);
	word[len] = '\0';
	return (word);
}

static void	ft_free_array(char **array, size_t size)
{
	while (size--)
		free(array[size]);
	free(array);
}

static char	**ft_help(char **array, const char *s, char c, const char *st)
{
	char	**temp_array;

	temp_array = array;
	while (*s)
	{
		if (*s != c)
		{
			st = s;
			while (*s && *s != c)
				s++;
			*array = ft_copyword(st, s - st);
			if (!*array)
			{
				ft_free_array(temp_array, array - temp_array);
				return (NULL);
			}
			array++;
		}
		else
			s++;
	}
	*array = NULL;
	return (temp_array);
}

char	**ft_split(const char *s, char c)
{
	size_t		count;
	char		**array;
	const char	*st;
	char		**temp_array;

	st = NULL;
	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	array = (char **)malloc((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	temp_array = ft_help(array, s, c, st);
	if (!temp_array)
	{
		return (NULL);
	}
	return (temp_array);
}

/*
int main() {
    const char* inputString = ",,,,,Hola,,,,,, Cómo,,,,,,, Estás,,,,,";
    char delimiter = ',';

    // Llamar a la función para dividir la cadena
    char** resultArray = ft_split(inputString, delimiter);

    // Imprimir las subcadenas resultantes
    int i = 0;
    while (resultArray[i] != NULL) {
        printf("%s\n", resultArray[i]);
        free(resultArray[i]);  // Liberar memoria de cada subcadena
        i++;
    }

    // Liberar la memoria del array de strings y del puntero
    free(resultArray);

    return 0;
}
*/
