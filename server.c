/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:57:01 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/09/24 18:39:26 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_SharedData	g_data;

void	handler_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
	{
		g_data.current_char |= (1 << (7 - g_data.bit_position));
	}
	g_data.bit_position++;
	if (g_data.bit_position == 8)
	{
		if (g_data.current_char == '\0')
			ft_printf("\nServidor: Fin del mensaje.\n");
		else
			ft_printf("%c", g_data.current_char);
		g_data.bit_position = 0;
		g_data.current_char = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_printf("Servidor: No se pudo enviar SIGUSR1\n");
	}
}

int	main(void)
{
	struct sigaction	sa_s;

	g_data.current_char = 0;
	g_data.bit_position = 0;
	ft_printf("Pid del servidor: %d\n", getpid());
	sa_s.sa_sigaction = &handler_signal;
	sa_s.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_s, NULL) == -1)
	{
		ft_printf("Error al manejar la señal SIGUSR1\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa_s, NULL) == -1)
	{
		ft_printf("Error al manejar la señal SIGUSR2\n");
		return (1);
	}
	while (1)
	{
		usleep(300);
	}
	return (0);
}
