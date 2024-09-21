/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secundarias.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:35 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/04/27 18:02:27 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_ft_putstr(char *s)
{
	int		i;
	int		count;
	char	*null;

	count = 0;
	null = "(null)";
	if (!s)
		s = null;
	i = 0;
	while (s[i] != 0)
	{
		write (1, &s[i], 1);
		count++;
		i++;
	}
	return (count);
}

int	pf_ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}

int	pf_ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += pf_ft_putstr("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += pf_ft_putchar ('-');
		n = -n;
	}
	if (n > 9)
	{
		count += pf_ft_putnbr (n / 10);
		count += pf_ft_putchar (n % 10 + '0');
	}
	else
	{
		count += pf_ft_putchar (n + '0');
	}
	return (count);
}

int	pf_ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += pf_ft_putnbr (n / 10);
		count += pf_ft_putchar (n % 10 + '0');
	}
	else
	{
		count += pf_ft_putchar (n + '0');
	}
	return (count);
}

int	pf_ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
