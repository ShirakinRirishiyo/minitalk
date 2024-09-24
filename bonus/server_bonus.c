#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libft.h"

volatile sig_atomic_t confirmation_received = 0;

void handle_signal(int sig)
{
    if (sig == SIGUSR1)
    {
        confirmation_received = 1; // Confirmación recibida
    }
}

static unsigned char current_byte = 0;

void handler_signal(int sig, siginfo_t *info, void *context)
{
    static int bit_position = 0;
    (void)context;

    if (sig == SIGUSR1)
        current_byte |= (1 << (7 - bit_position));

    bit_position++;

    if (bit_position == 8)
    {
        if (current_byte == '\0')
            printf("\nServidor: Fin del mensaje.\n");
        else
            printf("%c", current_byte); // Imprimir el byte recibido

        // Reiniciar para el siguiente byte
        bit_position = 0;
        current_byte = 0;

        // Enviar confirmación al cliente
        if (kill(info->si_pid, SIGUSR1) == -1)
            printf("Servidor: No se pudo enviar SIGUSR1\n");
    }
}

int main(void)
{
    struct sigaction sa_s;

    printf("Pid del servidor: %d\n", getpid());
    sa_s.sa_sigaction = &handler_signal;
    sa_s.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &sa_s, NULL) == -1)
    {
        printf("Error al manejar la señal SIGUSR1\n");
        return 1;
    }
    if (sigaction(SIGUSR2, &sa_s, NULL) == -1)
    {
        printf("Error al manejar la señal SIGUSR2\n");
        return 1;
    }
    while (1)
        usleep(200); // Espera a recibir señales

    return (0);
}
