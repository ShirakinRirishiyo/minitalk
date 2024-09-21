/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:36:46 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/07/06 11:36:46 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"


void handler_signal(int signal) 
{
	static struct
	{
        unsigned char current_character;
        int bit_position;
	} 
	state = {0, 0};
	if (signal == SIGUSR1)
	{
		state.current_character |= (1 << (7 - state.bit_position));
	}
	else if (signal == SIGUSR2)
	{
        // No se necesita hacer nada si es SIGUSR2
	}
	else
	{
		ft_printf("Señal no reconocida\n");
		return;
	}
	state.bit_position++;
	if (state.bit_position == 8)
	{
		if (state.current_character == '\0')
		{
			ft_printf("\nMensaje completo recibido.\n");
		}
		else
		{
			ft_printf("%c", state.current_character);
		}
		state.bit_position = 0;
		state.current_character = 0;
	}
}


int main(void)
{
	int	pid;
	
	pid = getpid();
	ft_printf("El pid es %d\n", pid);
	signal(SIGUSR1, handler_signal);
	signal(SIGUSR2, handler_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
