/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliente.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:08:48 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/06/29 14:08:48 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

void send_char(int pid, unsigned char character) 
{
    int i;
    unsigned char temp_char;

    for (i = 7; i >= 0; i--) {
        temp_char = (character >> i) & 1;
        if (temp_char == 0)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(100); // Aumentar el tiempo de espera para asegurar sincronización
    }
}

int main(int argc, char *argv[]) {
    int i;
    int pid_server;
    char *message;

    // Manejo de argumentos
    if (argc != 3) {
        printf("Uso: %s <PID_del_servidor> <mensaje>\n", argv[0]);
        return 1;
    }
    pid_server = atoi(argv[1]);

    // Asignación dinámica de memoria para el mensaje
    message = (char *)malloc(strlen(argv[2]) + 1);
    if (message == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }
    strcpy(message, argv[2]);

    // Enviar cada caracter del mensaje
    for (i = 0; i < strlen(message); i++) {
        send_char(pid_server, message[i]);
    }
    // Enviar el carácter nulo al final del mensaje
    send_char(pid_server, '\0');

    // Liberar la memoria asignada
    free(message);

    return 0;
}
