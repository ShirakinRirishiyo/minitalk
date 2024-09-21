/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:19:13 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/07 10:19:13 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;

	cdest = (unsigned char *)dest;
	csrc = (const unsigned char *)src;
	if (!dest && !src)
		return (0);
	if (cdest > csrc)
	{
		while (n--)
		{
			*(cdest + n) = *(csrc + n);
		}
	}
	else
	{
		while (n--)
		{
			*cdest++ = *csrc++;
		}
	}
	return (dest);
}

/*
int main()
{
	char dest[30] ="Jimmy";
	char src[] = "Jose Marti";

	ft_memmove(dest, src, 5);
	printf("Luego de memmove: %s\n", dest);
	return (0);
}
*/
