/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:31:30 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/04/22 15:31:30 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conversion_tools(va_list args, const char *format)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += pf_ft_putchar(va_arg(args, int));
	else if (*format == 'i' || *format == 'd')
		count += pf_ft_putnbr(va_arg(args, int));
	else if (*format == '%')
		count += pf_ft_putchar('%');
	else if (*format == 's')
		count += pf_ft_putstr(va_arg(args, char *));
	else if (*format == 'u')
		count += pf_ft_putnbr_u(va_arg(args, unsigned long));
	else if (*format == 'x' || *format == 'X')
		count += pf_ft_puthexa((unsigned long)va_arg(args, unsigned int), format);
	else if (*format == 'p')
	{
		count += pf_ft_putchar('0');
		count += pf_ft_putchar('x');
		count += pf_ft_puthexa((unsigned long)va_arg(args, void *), format);
	}
	return (count);
}
