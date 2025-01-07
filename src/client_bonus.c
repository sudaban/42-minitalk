/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:24:52 by sdaban            #+#    #+#             */
/*   Updated: 2025/01/06 14:11:57 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "printf/ft_printf.h"

static int	g_server_feedback_received = 0;

static void	send_bitstream(int server_pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
		{
			if (kill(server_pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		while (!g_server_feedback_received)
			;
		g_server_feedback_received = 0;
	}
}

static void	feedback_handler(int sig)
{
	if (sig == SIGUSR1)
		g_server_feedback_received = 1;
	else if (sig == SIGUSR2)
		ft_printf("Received message feedback\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					server_pid;

	if (argc != 3)
	{
		ft_printf("<Process ID of Server> <Message>", argv[0]);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		exit(EXIT_FAILURE);
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = feedback_handler;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	while (*argv[2])
		send_bitstream(server_pid, *argv[2]++);
	send_bitstream(server_pid, '\n');
	send_bitstream(server_pid, '\0');
}
