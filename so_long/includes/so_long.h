/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:45:48 by wwang             #+#    #+#             */
/*   Updated: 2022/04/16 19:08:29 by wwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"

typedef struct s_root
{
	int		fd;
	char	**map;
	int		map_height;
	int		map_width;

	int		player_count;
	int		color_count;
	int		exit_count;

	void	*ground;
	void	*tree;
	void	*player;
	void	*exit;
	void	*collectable;

	void	*mlxptr;
	void	*winptr;

	int		player_x;
	int		player_y;
	int		potions;
	int		step_counter;
}	t_root;

int		free_exit(t_root *game);
void	error_check(t_root *game);
int		read_map(t_root *game, char **argv);
void	img_init(t_root *game);
void	add_graphics(t_root *game);
int		key_handler(int key, t_root *game);
void	valid_chars(t_root *game);
#endif
