/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:47:44 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/02/03 18:45:26 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	signal_handler(int sig, siginfo_t *siginfo, void *ucontext)
{
	if (sig == SIGUSR1)
		return ;
	(void) siginfo;
	(void) ucontext;
	return ;
}

static void	send_signal(char *str, pid_t pid)
{
	int		bit;
	int		kill_return;

	while (*str)
	{
		bit = 8;
		while (bit--)
		{
			if ((*str >> bit) & 1)
			{
				kill_return = kill(pid, SIGUSR1);
				sleep(1);
			}
			else if (*str)
			{
				kill_return = kill(pid, SIGUSR2);
				sleep(1);
			}
			if (kill_return == -1)
				ft_error_exit("The kill() system call have failed");
		}
		str++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	char				*str;
	struct sigaction	sa;

	if (argc != 3)
		ft_error_exit("Usage: ./client server-PID string-to-send");
	pid = ft_atoi(argv[1]);
	str = argv[2];
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error_exit("Bad address or Invalid argument");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error_exit("Bad address or Invalid argument");
	send_signal(str, pid);
	return (0);
}
