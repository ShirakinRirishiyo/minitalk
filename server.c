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

void handler_signal(int signal) 
{
    static unsigned char current_character = 0;
    static int bit_position = 0;

    if (signal == SIGUSR1) 
    {
        current_character |= (1 << (7 - bit_position));
    }
    else if (signal == SIGUSR2)
    {
        // No es necesario hacer nada específico para SIGUSR2, solo avanzar bit_position
    }
    else
    {
        printf("Señal no reconocida\n");
        return;
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
        current_character = 0; // Reiniciar el caracter después de procesarlo
    }
}


int main(void)
{
    int pid;

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