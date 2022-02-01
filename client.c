/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:47:44 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/02/01 18:23:01 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;
	int		bit;

	if (argc != 3)
	{
		ft_putendl_fd("Usage: ./client server-PID string-to-send", 1);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	(void) pid;
	str = argv[2];
	while (*str)
	{
		bit = 8;
		while (bit)
		{
			bit--;
			if ((*str >> bit) & 1)
				ft_putchar_fd('1', 1);
			else if (*str)
				ft_putchar_fd('0', 1);
		}
		ft_putchar_fd('\n', 1);
		str++;
	}
	return (0);
}
