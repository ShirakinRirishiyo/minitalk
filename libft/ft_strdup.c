/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdrup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:51:02 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/08 19:51:02 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dest;
	char	*ptr;

	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	ptr = dest;
	while (*s1)
	{
		*dest++ = *s1++;
	}
	*dest = '\0';
	return (ptr);
}

/*
int main()
{
	const char *src = "   453Amores";
	char *result = ft_strdup(src);
	printf("%s\n", result);
	free(result);
	return (0);
}
*/
