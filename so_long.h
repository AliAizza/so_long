/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:10:32 by aaizza            #+#    #+#             */
/*   Updated: 2022/02/06 01:39:07 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

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

void	empty_map(char *line);
char	*ft_itoa(int n);
int		ft_strlen(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_checkline(char *s);
char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int len);
int		ft_strncmp(char *s1, char *s2, int n);
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
int		validate_component(int p, int e, char **map);
void	check_collision(t_Player *p);
int		close_window(t_vars *vars);
char	**read_file(int fd);
char	**ft_split(char *s, char c);
char	*ft_strdup(const char *s1);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);

#endif
