/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:47:44 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/02/11 15:08:20 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static volatile sig_atomic_t	g_got_confirmation = 0;

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_got_confirmation = 1;
}

static void	send_string_bit_by_bit(char *str, pid_t pid)
{
	int		bit;

	while (*str)
	{
		bit = 8;
		while (bit--)
		{
			if ((*str >> bit) & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error_exit("The kill() system call have failed");
			}
			else if (*str)
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_error_exit("The kill() system call have failed");
			}
			while (!g_got_confirmation)
				pause();
			g_got_confirmation = 0;
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
	sa.sa_flags = 0;
	sa.sa_handler = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error_exit("Bad address or Invalid argument");
	send_string_bit_by_bit(str, pid);
	return (0);
}
