/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgInitialiser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:09:13 by wwang             #+#    #+#             */
/*   Updated: 2022/04/16 19:11:21 by wwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putplayer(t_root *game, int h, int w);
void	putpotion(t_root *game, int h, int w);

void	img_init(t_root *game)
{
	int	x;
	int	y;

	game->ground = mlx_xpm_file_to_image(game->mlxptr,
			"img/Ground.xpm", &x, &y);
	game->tree = mlx_xpm_file_to_image(game->mlxptr, "img/Tree.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlxptr, "img/Link.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlxptr, "img/Tent.xpm", &x, &y);
	game->collectable = mlx_xpm_file_to_image(game->mlxptr,
			"img/Potion.xpm", &x, &y);
}

void	add_graphics(t_root *game)
{
	int	height;
	int	width;

	game->potions = 0;
	height = 0;
	while (height < game->map_height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'P')
				putplayer(game, height, width);
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->tree, width * 40, height * 40);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->ground, width * 40, height * 40);
			if (game->map[height][width] == 'C')
				putpotion(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->exit, width * 40, height * 40);
			width++;
		}
		height++;
	}
}

void	putplayer(t_root *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxptr,
		game->winptr, game->player, width * 40, height * 40);
	game->player_x = width;
	game->player_y = height;
}

void	putpotion(t_root *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxptr,
		game->winptr, game->collectable, width * 40, height * 40);
		game->potions++;
}
