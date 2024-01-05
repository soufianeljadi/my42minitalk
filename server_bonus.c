/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 04:19:40 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/04 23:21:33 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler_bonus(int signal, siginfo_t *info, void *s)
{
	static char		c;
	static int		bit;
	static int		pid;

	(void)s;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		bit = 0;
		c = 0;
	}
	if (signal == SIGUSR1)
		c = c + (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c != '\0')
			write(1, &c, 1);
		else
			kill(pid, SIGUSR1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("Server ID ->  %i\n", getpid());
	sig.sa_sigaction = sig_handler_bonus;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
