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
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void send_char(int pid, unsigned char character) 
{
    int i = 7;

    while (i >= 0) 
    {
        if ((character >> i) & 1) 
        {
            if (kill(pid, SIGUSR1) == -1) 
            {
                printf("Error al enviar SIGUSR1\n");
                exit(1);
            }
        } 
        else 
        {
            if (kill(pid, SIGUSR2) == -1) 
            {
                printf("Error al enviar SIGUSR2\n");
                exit(1);
            }
        }
        usleep(1000); // Incrementa el tiempo de espera
        i--;
    }
}

int main(int argc, char *argv[])
{
    size_t i;
    int pid_server;

	i = 0;
    if (argc != 3)
    {
        printf("Uso: %s <PID_del_servidor> <mensaje>\n", argv[0]);
        return (1);
    }
    pid_server = atoi(argv[1]);
	while(i < strlen(argv[2]))
	{
		send_char(pid_server, argv[2][i]);
		i++;
	}
    send_char(pid_server, '\0');
    return (0);
}
