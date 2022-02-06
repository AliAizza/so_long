/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:53:32 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/06 01:38:54 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_put(char c, va_list p)
{
	if (c == 'c')
		return (ft_putchar(va_arg(p, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(p, char *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	int		i;
	int		count;

	va_start(p, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_put(str[i + 1], p);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(p);
	return (count);
}
