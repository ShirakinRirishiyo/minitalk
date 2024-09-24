/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:52:49 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/09/24 18:39:21 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_SharedData	g_data;

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
	{
		g_data.confirmation = 1;
	}
}

void	setup_signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("Error al configurar SIGUSR1");
		exit(1);
	}
}

void	send_bit(int pid, unsigned char byte, int bit_position)
{
	if ((byte >> (7 - bit_position)) & 1)
	{
		kill(pid, SIGUSR1);
	}
	else
	{
		kill(pid, SIGUSR2);
	}
	usleep(200);
}

void	send_byte(int pid, unsigned char byte)
{
	int	attempt;
	int	bit_position;

	attempt = 0;
	while (attempt < 5)
	{
		g_data.confirmation = 0;
		bit_position = 0;
		while (bit_position < 8)
		{
			send_bit(pid, byte, bit_position);
			bit_position++;
			usleep(100);
			if (g_data.confirmation)
				break ;
		}
		if (g_data.confirmation)
		{
			ft_printf("Cliente: Received byte '%c'\n", byte);
			return ;
		}
		else
			ft_printf("Cliente: Fail to confirm byte '%c', retry...\n", byte);
		attempt++;
	}
}

int	main(int argc, char *argv[])
{
	size_t	i;
	int		pid_server;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Uso: %s <PID__server> <mensaje>\n", argv[0]);
		return (1);
	}
	pid_server = atoi(argv[1]);
	setup_signal_handler();
	while (i < strlen(argv[2]))
	{
		send_byte(pid_server, (unsigned char)argv[2][i]);
		i++;
	}
	send_byte(pid_server, '\0');
	return (0);
}
