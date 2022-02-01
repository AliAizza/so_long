/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:10:23 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/01 12:10:25 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(char **map, t_vars vars, t_Player *p, int rr)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				render_image(vars, g_naruto, p->y, p->x);
			else if (map[i][j] == '1' && rr)
				render_image(vars, "./images/wall.xpm", i, j);
			else if (map[i][j] == 'E')
				render_image(vars, g_door, i, j);
			else if (map[i][j] == 'C' && rr)
				render_image(vars, "./images/ramen.xpm", i, j);
			else if (map[i][j] == 'Y' && rr)
				render_image(vars, "./images/itachi.xpm", i, j);
			else if (map[i][j] != '0' && rr)
				exit(1);
			j++;
		}
		i++;
	}
}

void	render_background(char **map, t_vars vars)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			img = get_image(vars, "./images/floor.xpm");
			mlx_put_image_to_window (vars.mlx, vars.win, img, \
				j * PIXELS, i * PIXELS);
			j++;
		}
		i++;
	}
}

void	render_image(t_vars vars, char *path, int i, int j)
{
	void	*img;

	img = get_image(vars, path);
	mlx_put_image_to_window (vars.mlx, vars.win, img, \
		j * PIXELS, i * PIXELS);
}

void	render_pixel(t_vars vars, int i, int j)
{
	void	*img;

	img = get_image(vars, "./images/white_image.xpm");
	mlx_put_image_to_window (vars.mlx, vars.win, img, 0, 0);
	img = get_image(vars, "./images/floor.xpm");
	mlx_put_image_to_window (vars.mlx, vars.win, img, \
		j * PIXELS, i * PIXELS);
}
