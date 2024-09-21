/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:33:09 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/09 13:33:09 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int main()
{
    int j = 0;
    char str[] = "LAMADREQUETEPARIO09203942";
    char c;
 
    while (str[j]) {
        c = str[j];
        putchar(ft_tolower(c));
        j++;
    }
 
    return 0;
}*/

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (c + 32);
	}
	return (c);
}
