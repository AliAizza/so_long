/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:10:26 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/06 01:29:44 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_file(int fd)
{
	char	*str;
	char	*line;
	char	**map;

	line = get_next_line(fd);
	empty_map(line);
	str = NULL;
	while (line)
	{
		if (line[0] == '\n')
		{
			ft_printf("\n\033[0;31m=> EPMTY LINE IN THE MAP\n\n");
			exit(1);
		}
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(fd);
		g_size++;
	}
	close(fd);
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

void	get_player_and_enemies(char **map, t_Player *p, t_Enemy *e)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				p->y = i;
				p->x = j;
			}
			else if (map[i][j] == 'Y')
			{
				e[k].y = i;
				e[k].x = j;
				e[k++].dir = 1;
			}
		}
	}
}

void	check_coins_and_exit(t_vars vars, char **map, t_Player *p)
{
	char	*moves;

	if (map[p->y][p->x] == 'C')
	{
		g_ramen++;
		map[p->y][p->x] = 0;
		if (g_ramen == g_total_ramen)
			g_door = "./images/openeddoor.xpm";
		render_pixel(vars, p->y, p->x);
	}
	if (map[p->y][p->x] == 'E' && g_ramen == g_total_ramen)
	{
		ft_printf("\n\033[0;32m=> YOU WIN\n\n");
		exit(1);
	}
	moves = ft_itoa(g_move);
	mlx_string_put(vars.mlx, vars.win, 10, 10, 0x00000000, moves);
	free(moves);
}

void	get_direction(char **map, t_Enemy *e, int i)
{
	if (e[i].dir)
	{
		if (map[e[i].y + 1][e[i].x] != '1'
			&& map[e[i].y + 1][e[i].x] != 'E'
			&& map[e[i].y + 1][e[i].x] != 'C')
			e[i].y = e[i].y + 1;
		else
			e[i].dir = 0;
	}
	else
	{
		if (map[e[i].y - 1][e[i].x] != '1'
			&& map[e[i].y - 1][e[i].x] != 'E'
			&& map[e[i].y - 1][e[i].x] != 'C')
			e[i].y = e[i].y - 1;
		else
			e[i].dir = 1;
	}
}

void	*get_image(t_vars vars, char *path)
{
	int		img_w;
	int		img_h;
	void	*img;

	img = mlx_xpm_file_to_image(vars.mlx, path, &img_w, &img_h);
	return (img);
}
