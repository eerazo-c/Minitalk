/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:47:57 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/02/22 15:42:47 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/printf/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <signal.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	receive_signal(int sig)
{
	static int	oct = 0;
	static int	c = '\0';

	if (sig == SIGUSR1)
		c |= (0x01 << oct);
	oct++;
	if (oct == 8)
	{
		ft_putchar(c);
		oct = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("\e[0;31mWaiting receive signal\n\e[0;37mPID = %i\n", getpid());
	while (1)
	{
		signal(SIGUSR1, receive_signal);
		signal(SIGUSR2, receive_signal);
		usleep(10);
	}
	return (0);
}
