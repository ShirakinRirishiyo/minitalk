#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
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

void send_byte(int pid, unsigned char byte)
{
    int bit_position;
    int attempt;

    attempt = 0;
    while(attempt < 5)
        {
            bit_position = 0;
            confirmation_received = 0; // Reiniciar el estado de confirmación
            while (bit_position < 8)
        {
            if ((byte >> (7 - bit_position)) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);          
            usleep(500); // Ajusta el tiempo según sea necesario
            if (confirmation_received)
                break; // Salir si se recibe confirmación
            bit_position++;
        }
        if (confirmation_received)
        {
            printf("Cliente: Confirmación recibida para el byte '%c'\n", byte);
            break; // Salir si se recibió confirmación para el byte
        }
        else
            printf("Cliente: Fail to confirm byte '%c', retry...\n", byte);
		}
}



int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Uso: %s <PID_del_servidor> <mensaje>\n", argv[0]);
        return (1);
    }

    int pid_server = atoi(argv[1]);
    setup_signal_handler();

    // Enviar cada byte de la cadena (soporte para UTF-8)
    for (size_t i = 0; i < strlen(argv[2]); i++)
    {
        send_byte(pid_server, (unsigned char)argv[2][i]);
    }

    send_byte(pid_server, '\0'); // Enviar el carácter nulo para indicar fin del mensaje
    return (0);
}
