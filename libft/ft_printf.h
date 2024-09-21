/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:18:23 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/04/27 17:20:04 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include <libft>
# include "libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

int		ft_conversion_tools(va_list args, const char *format);
int		pf_ft_putchar(char c);
int		pf_ft_putstr(char *s);
int		pf_ft_putnbr(int n);
int		pf_ft_strlen(const char *s);
int		pf_ft_puthexa(unsigned long num, const char *format);
int		pf_ft_putnbr_u(unsigned int n);
int		ft_printf(const char *format, ...);

#endif
