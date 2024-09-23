#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

volatile sig_atomic_t confirmation_received = 0;

void handle_signal(int sig)
{
    if (sig == SIGUSR1)
    {
        confirmation_received = 1; // Confirmación recibida
    }
}

void setup_signal_handler(void)
{
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("Error al configurar SIGUSR1");
        exit(1);
    }
}

void send_char(int pid, unsigned char character)
{
    int bit_position;
    for (int attempt = 0; attempt < 5; attempt++) // Intentar hasta 5 veces
    {
        bit_position = 0;
        confirmation_received = 0; // Reiniciar el estado de confirmación

        while (bit_position < 8)
        {
            if ((character >> (7 - bit_position)) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);

            // Esperar un breve momento antes de verificar la confirmación
            usleep(300); // Ajusta el tiempo según sea necesario

            if (confirmation_received)
            {
                break; // Salir si se recibe confirmación
            }
            bit_position++;
        }

        if (confirmation_received)
        {
            printf("Cliente: Confirmación recibida para el carácter '%c'\n", character);
            break; // Salir si se recibió confirmación para el carácter
        }
        else
        {
            printf("Cliente: No se recibió confirmación para el carácter '%c', reintentando...\n", character);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        ft_printf("Uso: %s <PID_del_servidor> <mensaje>\n", argv[0]);
        return 1;
    }

    int pid_server = ft_atoi(argv[1]);
    setup_signal_handler();

    for (size_t i = 0; i < ft_strlen(argv[2]); i++)
    {
        send_char(pid_server, argv[2][i]);
    }

    send_char(pid_server, '\0'); // Enviar el carácter nulo para indicar fin del mensaje

    return 0;
}
