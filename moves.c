#include "so_long.h"

void	move_down(char **map, t_Player *p)
{
	if (map[p->y + 1][p->x] != '1' && map[p->y + 1][p->x] != 'E')
		p->y = p->y + 1;
	if (map[p->y + 1][p->x] == 'E' && g_ramen == g_total_ramen)
		p->y = p->y + 1;
}

void	move_up(char **map, t_Player *p)
{
	if (map[p->y - 1][p->x] != '1' && map[p->y - 1][p->x] != 'E')
		p->y = p->y - 1;
	if (map[p->y - 1][p->x] == 'E' && g_ramen == g_total_ramen)
		p->y = p->y - 1;
}

void	move_left(char **map, t_Player *p)
{
	if (map[p->y][p->x + 1] != '1' && map[p->y][p->x + 1] != 'E')
		p->x = p->x + 1;
	if (map[p->y][p->x + 1] == 'E' && g_ramen == g_total_ramen)
		p->x = p->x + 1;
	g_naruto = "./images/narutoleft.xpm";
}

void	move_right(char **map, t_Player *p)
{
	if (map[p->y][p->x - 1] != '1' && map[p->y][p->x - 1] != 'E')
		p->x = p->x - 1;
	if (map[p->y][p->x - 1] == 'E' && g_ramen == g_total_ramen)
		p->x = p->x - 1;
	g_naruto = "./images/narutoright.xpm";
}

int	validate_component(int p, int e)
{
	if (e < 1 || g_total_ramen < 1 || p != 1)
		return (0);
	return (1);
}
