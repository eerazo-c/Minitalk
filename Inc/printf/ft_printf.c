/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:24:55 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/02/16 16:33:58 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifi(char c, va_list args, int count_char)
{
	int	flag;

	flag = 0;
	if (c == '%')
		count_char += ft_put_char(c);
	if (c == 'c')
		count_char += ft_put_char(va_arg(args, int));
	if (c == 's')
		count_char += ft_put_str(va_arg(args, char *));
	if (c == 'i' || c == 'd')
		count_char += ft_put_nbr(va_arg(args, int));
	if (c == 'u')
		count_char += ft_put_nbr(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		count_char += ft_put_hex(va_arg(args, unsigned int), c);
	if (c == 'p')
	{
		count_char += ft_put_pointer(va_arg(args, void *));
	}
	if (flag == -1)
		return (-1);
	return (count_char);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		i;
	int		print;

	va_start(ap, str);
	i = 0;
	print = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			print = ft_specifi(str[++i], ap, print);
		else
			print += ft_put_char(str[i]);
		if (print == -1)
			return (-1);
		i++;
	}
	va_end(ap);
	return (print);
}
