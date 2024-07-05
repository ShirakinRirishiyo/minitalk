/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:06:20 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/06/29 14:06:20 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:06:20 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/06/29 14:06:20 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void	handler_signal(int signal) 
{
	static unsigned char	current_character;
	static int	bit_position;

	current_character = 0;
	bit_position = 0;
	if (signal == SIGUSR1)
	{
		current_character |= (1 << (7 - bit_position));
	}
	else if (signal == SIGUSR2)
    {

    }
	else
	{
		printf("Señal no reconocida\n");
		return (1);
    }
    bit_position++;
    if (bit_position == 8)
    {
        if (current_character == '\0')
        {
            printf("\nMensaje completo recibido.\n");
        } 
        else 
        {
            printf("%c", current_character);
        }
        bit_position = 0;
        current_character = 0; 
    }
}

int	main(void)
{
    int	pid;

    pid = getpid();
    printf("El pid es %d\n", pid);
    signal(SIGUSR1, handler_signal);
    signal(SIGUSR2, handler_signal);
    while(1)
    {
        pause ();
    }
    return (0);
}