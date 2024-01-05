/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 04:19:07 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/04 23:19:46 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	received(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Server successfully received message \n");
	exit (0);
}

void	check_bit_bonus(unsigned char tmp, int pid)
{
	if (tmp % 2 != 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("PID Invalid\n");
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("PID Invalid\n");
			exit(0);
		}
	}
}

void	send_char_bonus(int pid, char c)
{
	int				i;
	unsigned char	tmp;

	tmp = c;
	i = 0;
	while (i < 8)
	{
		tmp = c >> i;
		check_bit_bonus(tmp, pid);
		usleep(600);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;

	if (ac != 3 || av[2][0] == '\0')
	{
		ft_printf("Ivalid arguments !\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid server ID!\n");
		return (0);
	}
	i = 0;
	signal(SIGUSR1, received);
	while (av[2][i] != '\0')
	{
		send_char_bonus(pid, av[2][i]);
		i++;
	}
	send_char_bonus(pid, '\n');
	send_char_bonus(pid, '\0');
	return (0);
}
