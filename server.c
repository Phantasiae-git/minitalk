/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:31:22 by rfontes-          #+#    #+#             */
/*   Updated: 2023/05/13 20:31:03 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int		g_bit;

void	handler(int signal)
{
	static int	c;

	if (signal == SIGUSR1)
		c |= (1 << g_bit);
	if (g_bit == 7)
	{
		ft_printf("%c", c);
		g_bit = 0;
		c = 0;
		return ;
	}
	g_bit++;
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc > 1)
		return (1);
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
}
