/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:49:10 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/10/22 00:14:13 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		return (write (1, "(null)", 6));
	}
	while (str[i] != '\0')
	{
		if (ft_put_char(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
