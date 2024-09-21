/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:34:55 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/08 20:34:55 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			len;

	i = 0;
	if (s == NULL || f == NULL)
	{
		return ;
	}
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void	print_index_and_char(unsigned int index, char *c) {
    printf ("Index: %u, Char: %c\n", index, *c);
}

int main() 
{
    char str[] = "Hello";
    
    ft_striteri (str, &print_index_and_char);

    return (0);
}
*/