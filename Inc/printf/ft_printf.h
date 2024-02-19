/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:45:30 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/10/22 02:37:19 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# <biblioteca.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_specifi(char c, va_list args, int count_char);
int	ft_printf(char const *str, ...);
int	ft_put_char(int c);
int	ft_put_str(char *str);
int	ft_put_nbr(long num);
int	ft_put_long(long num);
int	ft_put_hex(unsigned long long num, char tp);
int	ft_put_pointer(void *num);

#endif
