/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:56:50 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/07/12 11:04:59 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "libft.h"

static unsigned char current_char = 0;

void handler_signal(int sig, siginfo_t *info, void *context)
{
    static int bit_position = 0;

    (void) context;
    if (sig == SIGUSR1)
        current_char |= (1 << (7 - bit_position));
    else if (sig == SIGUSR2)
    {
        // No hacer nada, solo avanzar la posición del bit
    }
    bit_position++;
    if (bit_position == 8)
    {
        if (current_char == '\0')
            ft_printf("\nServidor: Fin del mensaje.\n");
        else
            ft_printf("%c", current_char);
        bit_position = 0;
        current_char = 0;
        if (kill(info->si_pid, SIGUSR1) == -1)
            ft_printf("Servidor: No se pudo enviar SIGUSR1\n");
  
    }
}

int main(void)
{
    struct sigaction sa_s;

    ft_printf("Pid del servidor: %d\n", getpid());
    sa_s.sa_sigaction = &handler_signal;
    sa_s.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa_s, NULL) == -1)
    {
        ft_printf("Error al manejar la señal SIGUSR1\n");
        return (1);
    }
    if (sigaction(SIGUSR2, &sa_s, NULL) == -1)
    {
        ft_printf("Error al manejar la señal SIGUSR2\n");
        return (1);
    }
    while (1)
    {
        pause(); // Espera a recibir señales
    }
    return (0);
}
