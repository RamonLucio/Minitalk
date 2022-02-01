/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:47:44 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/02/01 19:55:21 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	error_exit(char *error)
{
	ft_putendl_fd(error, 1);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;
	int		bit;
	int		kill_return;

	if (argc != 3)
		error_exit("Usage: ./client server-PID string-to-send");
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		bit = 8;
		while (bit--)
		{
			if ((*str >> bit) & 1)
				kill_return = kill(pid, SIGUSR1);
			else if (*str)
				kill_return = kill(pid, SIGUSR2);
			if (kill_return == -1)
				error_exit("The kill() system call have failed");
		}
		str++;
	}
	return (0);
}
