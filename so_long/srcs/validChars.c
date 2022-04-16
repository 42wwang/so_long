/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validChars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:42:10 by wwang             #+#    #+#             */
/*   Updated: 2022/04/16 18:25:27 by wwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		valid_chars(t_root *game);
static void	check_count(t_root *game, int h, int w);

void	valid_chars(t_root *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map_height - 1)
	{
		width = 0;
		while (width <= game->map_width)
		{
			check_count(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->player_count == 1
			&& game->color_count > 1
			&& game->exit_count == 1))
	{
		printf("\e[31m\e[1mError\n"
			"Game components incorrect, only 1 player, 1 exit allowed,"
			"potions need to be more than one! \e[1m \n");
		free_exit(game);
	}
}

static void	check_count(t_root *game, int h, int w)
{
	if (game->map[h][w] != '1' &&
		game->map[h][w] != '0' &&
		game->map[h][w] != 'P' &&
		game->map[h][w] != 'E' &&
		game->map[h][w] != 'C' &&
		game->map[h][w] != '\n')
	{
		printf("\e[31m\e[1mError\nUnknown characters in the map!! \e[0m \n");
		printf("This char is failing%c\n", game->map[h][w]);
		free_exit(game);
	}
	if (game->map[h][w] == 'C')
		game->color_count++;
	if (game->map[h][w] == 'P')
		game->player_count++;
	if (game->map[h][w] == 'E')
		game->exit_count++;
}
