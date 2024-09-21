/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:01:05 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/05 16:01:05 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	resultado;
	int	signo;

	resultado = 0;
	signo = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		signo = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		resultado = resultado * 10 + (*nptr - '0');
		nptr++;
	}
	return (resultado * signo);
}

/*int main()
{
    const char nptr[] = "  23202-32";
    int resultado = ft_atoi(nptr); 
    printf("El número convertido es: %d\n", resultado); 
    return (0);
}*/
