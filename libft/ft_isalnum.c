/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:02:30 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/06 11:02:30 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isdigit(c)) || (ft_isalpha(c)));
}

/*int main() 
{
    char    c;

    // Solicitar al usuario que ingrese un carácter
    printf("Ingrese un carácter: ");
    scanf("%c", &c);
	
    if (isalnum(c))
    {
        printf("%c es un carácter alfanumérico.\n", c);
    }
    else
    {
        printf("%c no es un carácter alfanumérico.\n", c);
    }
    return (0);
}*/