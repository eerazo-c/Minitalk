/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 02:39:38 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/10/22 13:29:18 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_long(long num)
{
	int	count;
	int	check;

	if (num < 10)
		return (ft_put_char(num + '0'));
	else
		count = ft_put_long(num / 10);
	if (count == -1)
		return (-1);
	check = ft_put_char((num % 10) + '0');
	if (check == -1)
		return (-1);
	return (count + check);
}

int	ft_put_nbr(long num)
{
	int	count;
	int	check;

	count = 0;
	if (num < 0)
	{
		count = ft_put_char('-');
		num *= -1;
	}
	if (count == -1)
		return (-1);
	check = ft_put_long(num);
	if (check == -1)
		return (-1);
	return (count + check);
}
