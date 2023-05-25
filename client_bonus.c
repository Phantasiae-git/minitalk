/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:02:42 by rfontes-          #+#    #+#             */
/*   Updated: 2023/05/13 20:32:58 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void	confirm(int signal)
{
	static int	i;

	if (signal == SIGUSR1 && !i++)
		ft_printf("Success!\n");
}

void	send(char *string, pid_t server_pid)
{
	size_t	i;
	size_t	bit;

	i = -1;
	while (string[++i])
	{
		bit = 0;
		while (bit < 8)
		{
			if (string[i] & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(200);
			string[i] = string[i] >> 1;
			bit++;
		}
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*string;

	string = argv[2];
	if (argc != 3)
	{
		ft_printf("Wrong format.\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, confirm);
	send(string, server_pid);
}
