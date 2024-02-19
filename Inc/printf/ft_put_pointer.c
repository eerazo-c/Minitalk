/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:35:13 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/10/22 00:58:50 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put_pointer(void *num)
{
	int	count;
	int	check;

	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	check = ft_put_hex((unsigned long long)num, 'x');
	if (check == -1)
		return (-1);
	return (count + check);
}
