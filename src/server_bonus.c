/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:24:41 by sdaban            #+#    #+#             */
/*   Updated: 2025/01/06 13:01:37 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "printf/ft_printf.h"

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	received_char = 0;
	static unsigned int		bit_position = 0;

	(void)context;
	if (sig == SIGUSR1)
		received_char <<= 1;
	else if (sig == SIGUSR2)
		received_char = (received_char << 1) | 1;
	bit_position++;
	if (bit_position == 8)
	{
		ft_printf("%c", received_char);
		if (received_char == '\0')
		{
			if (kill(info->si_pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		received_char = 0;
		bit_position = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	ft_printf("Process ID: %d\n", getpid());
	while (1)
		pause();
}
