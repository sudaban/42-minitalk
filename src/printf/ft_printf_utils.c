/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:54:34 by sdaban            #+#    #+#             */
/*   Updated: 2024/10/30 10:54:34 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_int(int a)
{
	if (a == -2147483648)
		return (write(1, "-2147483648", 11));
	return (ft_putnbr(a));
}

int	ft_hex(unsigned int a, char c)
{
	int	ret;
	int	write_ret;

	ret = 0;
	if (a >= 16)
	{
		ret += ft_hex(a / 16, c);
		if (ret == -1)
			return (-1);
	}
	if (c == 'X')
		write_ret = write(1, &"0123456789ABCDEF"[a % 16], 1);
	else if (c == 'x')
		write_ret = write(1, &"0123456789abcdef"[a % 16], 1);
	else
		return (-1);
	if (write_ret == -1)
		return (-1);
	return (ret + write_ret);
}

int	ft_point(unsigned long a, int sign)
{
	int	ret;
	int	write_ret;

	ret = ft_point_prefix(a, sign);
	if (ret == -1)
		return (-1);
	if (a == 0 && sign == 1)
		return (ret);
	if (a == 0)
	{
		write_ret = write(1, "0", 1);
		if (write_ret == -1)
			return (-1);
		return (ret + write_ret);
	}
	write_ret = ft_point_recursive(a);
	if (write_ret == -1)
		return (-1);
	return (ret + write_ret);
}

int	ft_string(char *str)
{
	int	i;
	int	ret;
	int	write_ret;

	i = 0;
	ret = 0;
	if (!str)
	{
		write_ret = write(1, "(null)", 6);
		if (write_ret == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		write_ret = write(1, &str[i], 1);
		if (write_ret == -1)
			return (-1);
		ret += write_ret;
		i++;
	}
	return (ret);
}

int	ft_unsigned(unsigned int a)
{
	int	ret;
	int	write_ret;

	ret = 0;
	if (a >= 10)
	{
		ret += ft_unsigned(a / 10);
		if (ret == -1)
			return (-1);
	}
	write_ret = write(1, &"0123456789"[a % 10], 1);
	if (write_ret == -1)
		return (-1);
	return (ret + write_ret);
}
