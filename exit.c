/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:09:53 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/01 13:08:46 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*c;
	char	*s;

	i = 0;
	s = (char *)s1;
	while (s[i])
		i++;
	c = malloc((i + 1) * sizeof(char));
	if (!c)
		return (NULL);
	i = 0;
	while (s[i])
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}