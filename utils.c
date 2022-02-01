/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:10:36 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/01 12:10:36 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_convert(long int nb, int size, int sign)
{
	char	*a;

	a = malloc((size + 1) * sizeof(char));
	if (!a)
		return (NULL);
	a[size] = '\0';
	size--;
	while (size >= 0)
	{
		a[size] = (nb % 10) + '0';
		nb /= 10;
		size--;
	}
	if (sign == 0)
		a[0] = '-';
	return (a);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			sign;
	int			size;
	long int	nbr;

	sign = 1;
	size = 0;
	nb = n;
	nbr = n;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		sign--;
		size++;
		nb *= -1;
		nbr *= -1;
	}
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	return (ft_convert(nbr, size, sign));
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}
