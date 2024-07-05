#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void send_char(int pid, unsigned char character)
{
    int i = 7;

    while (i >= 0)
    {
        if ((character >> i) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(200); // Espera para asegurar que el servidor pueda procesar la señal
        i--;
    }
}

void handle_signal(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("Cliente: Recibida señal SIGUSR1\n");
    }
    else if (sig == SIGUSR2)
    {
        printf("Cliente: Recibida señal SIGUSR2\n");
    }
}

void manejo(size_t i, int pid_server, char *mensaje)
{
    struct sigaction sa_s;
	 // Configurar el manejador para SIGUSR1
    sa_s.sa_handler = handle_signal;
    sa_s.sa_flags = 0;
    sigemptyset(&sa_s.sa_mask); // Limpiar el conjunto de señales bloqueadas
    if (sigaction(SIGUSR1, &sa_s, NULL) == -1)
    {
        perror("Error al configurar SIGUSR1");
        return;
    }
    if (sigaction(SIGUSR2, &sa_s, NULL) == -1)
    {
        perror("Error al configurar SIGUSR2");
        return;
    }
    i = 0;
    while (i < strlen(mensaje))
    {
        send_char(pid_server, mensaje[i]);
        i++;
    }
}

int main(int argc, char *argv[])
{
    size_t i;
    int pid_server;
    char *mensaje;

    i = 0;
    if (argc != 3)
    {
        printf("Uso: %s <PID_del_servidor> <mensaje>\n", argv[0]);
        return (1);
    }
    pid_server = atoi(argv[1]);
    mensaje = (char *)malloc(strlen(argv[2]) + 1);
    if (mensaje == NULL)
    {
        printf("Error al asignar memoria\n");
        return (1);
    }
    strcpy(mensaje, argv[2]);
    manejo(i, pid_server, mensaje);
    send_char(pid_server, '\0'); // Enviar el caracter nulo para indicar fin del mensaje
    free(mensaje);
    return (0);
}