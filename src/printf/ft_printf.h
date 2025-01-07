/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:54:39 by sdaban            #+#    #+#             */
/*   Updated: 2024/10/30 10:54:39 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_atoi(char *str);
int	ft_putchar(char a);
int	ft_putnbr(int n);
int	ft_printf(const char *str, ...);
int	ft_int(int a);
int	ft_hex(unsigned int a, char c);
int	ft_point(unsigned long a, int sign);
int	ft_string(char *str);
int	ft_unsigned(unsigned int a);
int	ft_point_prefix(unsigned long a, int sign);
int	ft_point_recursive(unsigned long a);

#endif
