/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:30:24 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/04/27 18:11:26 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_ft_puthexa(unsigned long num, const char *format)
{
	const char	*hexa_min;
	const char	*hexa_may;
	const char	*hex_chars;
	int			count;

	hexa_min = "0123456789abcdef";
	hexa_may = "0123456789ABCDEF";
	count = 0;
	if (*format == 'X')
	{
		hex_chars = hexa_may;
	}
	else
	{
		hex_chars = hexa_min;
	}
	if (num >= 16)
		count += pf_ft_puthexa(num / 16, format);
	count += pf_ft_putchar(hex_chars[num % 16]);
	return (count);
}
