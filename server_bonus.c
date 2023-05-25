/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:31:22 by rfontes-          #+#    #+#             */
/*   Updated: 2023/05/13 20:34:32 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int		g_bit;

// void tester(int signal)
// {

// 	if(signal==SIGUSR1)
// 		ft_printf("1");
// 	else if(signal==SIGUSR2)
// 		ft_printf("0");
// 	if(g_bit==7)
// 	{
// 		ft_printf(" ");
// 		g_bit=0;
// 		return ;
// 	}
// 	g_bit++;
// }

void	handler(int signal, siginfo_t *siginfo, void *a)
{
	static int	c;

	(void)a;
	if (signal == SIGUSR1)
		c |= (1 << g_bit);
	if (g_bit == 7)
	{
		ft_printf("%c", c);
		kill(siginfo->si_pid, SIGUSR1);
		g_bit = 0;
		c = 0;
		return ;
	}
	g_bit++;
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sa;

	if (argc > 1)
		return (1);
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		pause();
	}
}
