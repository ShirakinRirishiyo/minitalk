/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:39:56 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/07/01 16:39:56 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void send_char(int pid, unsigned char character) 
{
    int i = 7;

    while (i >= 0) 
    {
        // Extrae el bit más significativo y envía la señal correspondiente
        if ((character >> i) & 1) 
        {
            kill(pid, SIGUSR1); // Envia SIGUSR1 si el bit es 1
        } 
        else 
        {
            kill(pid, SIGUSR2); // Envia SIGUSR2 si el bit es 0
        }
        usleep(200); // Espera para asegurar que el servidor pueda procesar la señal
        i--;
    }
}

int	main(int argc, char *argv[])
{
	size_t	i;
	int     pid_server;
	char    *message;

	i = 0;
	if (argc != 3)
	{
		printf("Uso: %s <PID_del_servidor> <mensaje>\n", argv[0]);
		return (1);
	}
	pid_server = atoi(argv[1]);
	message = (char *)malloc(strlen(argv[2]) + 1);
	if (message == NULL)
	{
		printf("Error al asignar memoria\n");
		return (1);
	}
	strcpy(message, argv[2]); 
	while( i < strlen(message))
	{
		send_char(pid_server, message[i]);
		i++;
	}
	send_char(pid_server, '\0');
	free(message);
	return (0);
}