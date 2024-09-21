/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:30:14 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/09 13:30:14 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int main()
{
    int j = 0;
    char str[] = "dejebetudejebe090112\n";
    char c;
 
    while (str[j]) {
        c = str[j];
        putchar(ft_toupper(c));
        j++;
    }
 
    return 0;
}*/

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	return (c);
}
