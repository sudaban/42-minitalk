/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:46:43 by sdaban            #+#    #+#             */
/*   Updated: 2024/12/11 12:48:26 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char a)
{
	return (write(1, &a, 1));
}

int	ft_putnbr(int n)
{
	int	ret;
	int	write_ret;

	ret = 0;
	if (n < 0)
	{
		write_ret = write(1, "-", 1);
		if (write_ret == -1)
			return (-1);
		ret += write_ret;
		n = -n;
	}
	if (n >= 10)
	{
		ret += ft_putnbr(n / 10);
		if (ret == -1)
			return (-1);
	}
	write_ret = write(1, &"0123456789"[n % 10], 1);
	if (write_ret == -1)
		return (-1);
	return (ret + write_ret);
}

int	ft_point_prefix(unsigned long a, int sign)
{
	int	write_ret;

	if (a == 0 && sign == 1)
	{
		write_ret = write(1, "(nil)", 5);
		if (write_ret == -1)
			return (-1);
		return (write_ret);
	}
	if (sign == 1)
	{
		write_ret = write(1, "0x", 2);
		if (write_ret == -1)
			return (-1);
		return (write_ret);
	}
	return (0);
}

int	ft_point_recursive(unsigned long a)
{
	int	ret;
	int	write_ret;

	ret = 0;
	if (a >= 16)
		ret += ft_point_recursive(a / 16);
	write_ret = write(1, &"0123456789abcdef"[a % 16], 1);
	if (write_ret == -1)
		return (-1);
	return (ret + write_ret);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
