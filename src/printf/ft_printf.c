/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:54:28 by sdaban            #+#    #+#             */
/*   Updated: 2024/11/13 10:33:07 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_format(va_list *args, char c)
{
	int	ret;

	ret = 0;
	if (c == 'u')
		ret = ft_unsigned(va_arg((*args), unsigned int));
	else if (c == 'c')
		ret = ft_putchar(va_arg((*args), int));
	else if (c == 'i' || c == 'd')
		ret = ft_int(va_arg((*args), int));
	else if (c == 'x' || c == 'X')
		ret = ft_hex(va_arg((*args), unsigned int), c);
	else if (c == 'p')
		ret = ft_point(va_arg((*args), unsigned long), 1);
	else if (c == 's')
		ret = ft_string(va_arg((*args), char *));
	else if (c == '%')
		ret = ft_putchar('%');
	if (ret == -1)
		return (-1);
	return (ret);
}

static int	handle_format(va_list *args, const char *str, int *i)
{
	int	ret;

	ret = 0;
	if (str[*i] == '%')
	{
		ret = ft_format(args, str[*i + 1]);
		(*i)++;
	}
	else
		ret = ft_putchar(str[*i]);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		ret;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		ret = handle_format(&args, str, &i);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		len += ret;
		i++;
	}
	va_end(args);
	return (len);
}
