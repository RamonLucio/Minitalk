/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:47:48 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/02/03 19:08:42 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	signal_handler(int sig, siginfo_t *siginfo, void *ucontext)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("1", 1);
		kill(siginfo->si_pid, SIGUSR1);
	}
	if (sig == SIGUSR2)
	{
		ft_putstr_fd("0", 1);
		kill(siginfo->si_pid, SIGUSR1);
	}
	(void) ucontext;
	return ;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error_exit("Bad address or Invalid argument");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error_exit("Bad address or Invalid argument");
	while (1)
		pause();
	return (0);
}
