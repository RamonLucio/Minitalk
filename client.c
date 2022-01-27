/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:47:44 by rlucio-l          #+#    #+#             */
/*   Updated: 2022/01/27 18:23:55 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

int	main(int argc, char *argv[])
{
	(void) argv;
	if (argc != 3)
	{
		ft_putendl_fd("Usage: ./client server-PID string-to-send", 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}
