/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:36:12 by sdaban            #+#    #+#             */
/*   Updated: 2025/01/06 13:14:21 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "printf/ft_printf.h"

void	handle_signal(int signal)
{
	static int	count_bit = 0;
	static char	character = 0;

	if (signal == SIGUSR1)
		character |= (1 << (7 - count_bit));
	count_bit++;
	if (count_bit == 8)
	{
		write(1, &character, 1);
		count_bit = 0;
		character = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Process ID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
	}
}
