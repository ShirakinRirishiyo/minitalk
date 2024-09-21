/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:57:02 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/07/06 12:57:02 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <libft.h>

void send_char(int pid, unsigned char character)
{
    int i = 7;

    while (i >= 0)
    {
        if ((character >> i) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(250); // Espera para asegurar que el servidor pueda procesar la señal
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

void manejo(void)
{
    struct sigaction sa_s;
    sa_s.sa_handler = handle_signal;
    sa_s.sa_flags = 0;
    sigemptyset(&sa_s.sa_mask); // Limpiar el conjunto de señales bloqueadas
    if (sigaction(SIGUSR1, &sa_s, NULL) == -1)
    {
        ft_printf("Error al configurar SIGUSR1\n");
       exit(1);
    }
    if (sigaction(SIGUSR2, &sa_s, NULL) == -1)
    {
        ft_printf("Error al configurar SIGUSR2\n");
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    size_t i;
    int pid_server;

    i = 0;
    if (argc != 3)
    {
        ft_printf("Uso: %s <PID_del_servidor> <mensaje>\n", argv[0]);
        return (1);
    }
    pid_server = ft_atoi(argv[1]);
    manejo();
    i = 0;
    while (i < ft_strlen(argv[2]))
    {
        send_char(pid_server, argv[2][i]);
        i++;
    }
    send_char(pid_server, '\0'); // Enviar el caracter nulo para indicar fin del mensaje
    return (0);
}
