/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:40:18 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/09 16:40:18 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && !len)
	{
		return (NULL);
	}
	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j])
			&& (needle[j] != '\0')
			&& ((i + j) < len))
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

/*
int main()
{
	const char *pajar = "Una vez, te vi al lado del río";
	const char *aguja = "lado";
	size_t len = ft_strlen(pajar);

	char *result = ft_strnstr(pajar, aguja, len);

	if(result != NULL){
		printf("Se encuentra en la posición: %ld\n", result - pajar);
	}
	else{
		printf("No se encuentra\n");
	}
	return (0);
}
*/