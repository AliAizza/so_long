#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define PIXELS 50

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_Player
{
	int	x;
	int	y;
}	t_Player;

typedef struct s_Enemy
{
	int	x;
	int	y;
	int	dir;
}	t_Enemy;

int			g_move;
int			g_total_ramen;
int			g_ramen;
int			g_itachi;
int			g_size;
int			g_frame;
char		*g_door;
char		*g_naruto;

int		validate_map(char *path, char **map, int count);
void	render_background(char **map, t_vars vars);
void	render_image(t_vars vars, char *path, int i, int j);
void	render_pixel(t_vars vars, int i, int j);
void	render_map(char **map, t_vars vars, t_Player *p, int rr);
void	move_down(char **map, t_Player *p);
void	move_up(char **map, t_Player *p);
void	move_left(char **map, t_Player *p);
void	move_right(char **map, t_Player *p);
void	get_player_and_enemies(char **map, t_Player *p, t_Enemy *e);
void	check_coins_and_exit(t_vars g_vars, char **map, t_Player *p);
void	get_direction(char **map, t_Enemy *e, int i);
void	*get_image(t_vars vars, char *path);
int		validate_component(int p, int e);
void	check_collision(t_Player *p);
int		close_window(t_vars *vars);
char	*read_file(int fd);

#endif
