/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorHandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:44:44 by wwang             #+#    #+#             */
/*   Updated: 2022/04/16 18:16:55 by wwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_walls(t_root *game);
static int	horizontal(t_root *game);
static int	vertical(t_root *game);

void	error_check(t_root *game)
{
	check_walls(game);
	valid_chars(game);
}

static void	check_walls(t_root *game)
{
	int	verwalls;
	int	horwalls;

	verwalls = vertical(game);
	horwalls = horizontal(game);
	if (!verwalls || !horwalls)
	{
		printf("\e[31m\e[1mError\nMap is missing walls, map unacceptable \e[0m \n");
		free_exit(game);
	}
}

static int	horizontal(t_root *game)
{
	int	width;
	int	i;

	width = game->map_width;
	i = 0;
	while (i < width)
	{
		if (game->map[0][i] != '1'
			|| game->map[game->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	vertical(t_root *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->map_width;
	while (height < game->map_height)
	{
		if (game->map[height][0] != '1'
			|| game->map[height][width - 1] != '1')
			return (0);
		height++;
	}
	return (1);
}
