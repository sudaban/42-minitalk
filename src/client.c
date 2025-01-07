/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:36:00 by sdaban            #+#    #+#             */
/*   Updated: 2025/01/06 13:14:45 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "printf/ft_printf.h"

void	send_signal(int pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i--;
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*message;

	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		if (server_pid <= 0)
		{
			exit(EXIT_FAILURE);
		}
		message = av[2];
		send_signal(server_pid, message);
		send_signal(server_pid, "\n");
	}
	else
		ft_printf("<Process ID of Server> <Message>", av[0]);
	return (0);
}
