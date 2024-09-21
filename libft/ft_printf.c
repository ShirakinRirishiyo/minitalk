/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:30:24 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/04/27 14:52:11 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		count;

	if (!format)
		return (0);
	count = 0;
	va_start(arguments, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += ft_conversion_tools(arguments, (char *)format);
			format++;
		}
		else
		{
			count += pf_ft_putchar(*format);
			format++;
		}
	}
	va_end(arguments);
	return (count);
}
