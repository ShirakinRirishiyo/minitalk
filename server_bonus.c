/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:01:33 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/07/05 17:06:06 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static unsigned char current_char = 0;

void handler_signal(int sig, siginfo_t *info, void *context)
{
    static int bit_position = 0;

    (void) context;
    if(sig == SIGUSR1)
    {
        current_char |= (1 << (7 - bit_position));
    }
    else if(sig == SIGUSR2)
    {
        // Do nothing, just advance the bit position
    }
    bit_position++;
    if(bit_position == 8)
    { 
        printf("%c\n", current_char);
        bit_position = 0;
        current_char = 0;
        if (kill(info->si_pid, SIGUSR1) == -1)
        {
           printf("Unable to send SIGUSR1\n");
        }
    }
}

int main(void)
{
    struct sigaction    sa_s;

    printf("Pid del servidor: %d\n", getpid());
    sa_s.sa_sigaction = &handler_signal;
    sa_s.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa_s, NULL) == -1)
    {
        printf("Error al manejar la señal SIGUSR1\n");
        return (1);
    }
    if (sigaction(SIGUSR2, &sa_s, NULL) == -1)
    {
        printf("Error al manejar la señal SIGUSR2\n");
        return (1);
    }
    while (1)
    {
        pause(); // Espera a recibir señales
    }
    return (0);
}
