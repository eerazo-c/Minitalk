/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:51:56 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/02/16 15:15:11 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put_hex(unsigned long long num, char tp)
{
	char	*hex_val;
	int		count;
	int		check;

	count = 0;
	if (tp == 'X')
		hex_val = "0123456789ABCDEF";
	else
		hex_val = "0123456789abcdef";
	if (num > 15)
		count = ft_put_hex(num / 16, tp);
	else
		return (ft_put_char(hex_val[num]));
	if (count == -1)
		return (-1);
	check = ft_put_char(hex_val[num % 16]);
	if (check == -1)
		return (-1);
	return (count + check);
}
