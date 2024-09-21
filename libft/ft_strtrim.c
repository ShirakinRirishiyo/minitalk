/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:47:35 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/09 13:47:35 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	size_t	len;
	char	*cropped;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (end > start && is_in_set(s1[end], set))
		end--;
	len = end - start + 1;
	cropped = (char *)malloc(len + 1);
	if (cropped == NULL)
		return (NULL);
	ft_memcpy(cropped, s1 + start, len);
	cropped[len] = '\0';
	return (cropped);
}

/*int main() {
    // Ejemplo 1
    const char *s1 = "Hola, mundo!";
    const char *set = "mundo! ";
    char *result1 = ft_strtrim(s1, set);
    printf("Original: '%s'\n", s1);
    printf("Trimmed:  '%s'\n\n", result1);
    free(result1);

    // Ejemplo 2
    const char *s2 = "12345";
    const char *set2 = "1235";
    char *result2 = ft_strtrim(s2, set2);
    printf("Original: '%s'\n", s2);
    printf("Trimmed:  '%s'\n\n", result2);
    free(result2);

    // Ejemplo 3
    const char *s3 = "abcde";
    const char *set3 = "abc";
    char *result3 = ft_strtrim(s3, set3);
    printf("Original: '%s'\n", s3);
    printf("Trimmed:  '%s'\n\n", result3);
    free(result3);

    return 0;
}*/
