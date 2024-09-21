/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:14:07 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/12 12:59:40 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_makepositive(int n, int *sign, unsigned int *temp)
{
	if (n < 0)
	{
		*sign = 1;
		*temp = (unsigned int)(-n);
	}
	else
		*temp = (unsigned int)n;
	return (1);
}

static size_t	ft_conteo(int n)
{
	size_t			cifra;
	unsigned int	temp;

	cifra = 0;
	if (n < 0)
	{
		temp = (unsigned int)(-n);
	}
	else
	{
		temp = (unsigned int)n;
	}
	while (temp > 0)
	{
		temp /= 10;
		cifra++;
	}
	return (cifra);
}

static char	*allocate_memory(int sign, size_t cifra)
{
	char	*result;

	result = (char *)malloc((cifra + sign + 1) * sizeof(char));
	return (result);
}

static void	ft_signconver(int sign, char *result, unsigned int temp, size_t i)
{
	while (temp > 0)
	{
		result[i--] = (temp % 10) + '0';
		temp /= 10;
	}
	if (sign)
		result[i] = '-';
}

char	*ft_itoa(int n)
{
	unsigned int	temp;
	int				sign;
	size_t			cifra;
	char			*result;
	size_t			i;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	cifra = ft_conteo(n);
	ft_makepositive(n, &sign, &temp);
	result = allocate_memory(sign, cifra);
	if (result == NULL)
		return (NULL);
	i = cifra + sign - 1;
	ft_signconver(sign, result, temp, i);
	result[cifra + sign] = '\0';
	return (result);
}

/*
int main() {
    int num = 5232095;
    char* str = ft_itoa(num);
    printf("Número: %d, Cadena: %s\n", num, str);

    // Liberar la memoria asignada dinámicamente si no es NULL
    if (str != NULL) {
        free(str);
    }

    return (0);
} 
*/
