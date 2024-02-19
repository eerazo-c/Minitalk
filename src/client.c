/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:47:19 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/02/19 18:20:24 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
   	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void	send_sign(char *msj, int pid)
{
	int	i;
	int	char_kit;
	int	bit;

	i = -1;
	while (msj[++i])
	{
		char_kit = msj[i];
		bit = 0;
		while (bit < 8)
		{
			if ((char_kit & (0x01 << bit)) != 0)
			{
				kill(pid, SIGUSR1);
				usleep(10);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(10);
			}
			usleep(10);
			bit++;
		}
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_sign(av[2], pid);
	}
	else
		write(1, "These arguments not are correct", 31);
	return (0);
}
