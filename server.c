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
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int signal_received = 0;  // Contador global de señales recibidas

void handler_signal(int signal) 
{
    static int bit_position = 0;
    static unsigned char current_character = 0;

    signal_received++;  // Incrementar contador global de señales recibidas

    if (signal == SIGUSR1 || signal == SIGUSR2) {
        current_character |= (signal == SIGUSR1) ? (1 << (7 - bit_position)) : 0;
        bit_position++;

        if (bit_position == 8) {
            if (current_character == '\0') {
                printf("\nMensaje completo recibido.\n");
            } else {
                printf("%c", current_character);
            }
            bit_position = 0;
            current_character = 0;
        }
    } else {
        printf("Señal no reconocida\n");
    }
}

int main(void) {
    int pid;

    pid = getpid();
    printf("El pid es %d\n", pid);

    signal(SIGUSR1, handler_signal);
    signal(SIGUSR2, handler_signal);

    while (1) {
        pause(); // Esperar otra señal
    }

    return 0;
}
