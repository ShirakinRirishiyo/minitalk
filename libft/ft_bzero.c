/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:26:59 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/06 10:26:59 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*int	main()
{
	char s[] = "Poder";
	size_t n = strlen(s);
	 ft_bzero(s, n);
	printf("El resultado de la conversion es: %s\n", s);
	free(char);
	return (0);
 }*/
