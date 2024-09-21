/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:07:19 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/08 20:07:19 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)&s[i]);
}

/*
int main()
{
	char *resultado;
	char *s ="Poor Things";
	int n = 'T';

	resultado = ft_strchr(s, n);
	if(resultado == NULL)
	printf("No se encontro");
	else
	printf("Se encontró en: %s/n", resultado);
	return (0);
}
*/