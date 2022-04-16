/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerMovements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:02:29 by wwang             #+#    #+#             */
/*   Updated: 2022/04/12 16:30:16 by wwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	up_down(t_root *game, int key);
static	int	left_right(t_root *game, int key);
static	int	valid_move(t_root *game, int x, int y);

int	key_handler(int key, t_root *game)
{
	int	move;

	if (key == 53)
		free_exit(game);
	if (key == 13)
		move = up_down(game, key);
	if (key == 1)
		move = up_down(game, key);
	if (key == 0)
		move = left_right(game, key);
	if (key == 2)
		move = left_right(game, key);
	if (move)
		add_graphics(game);
	return (1);
}

/* This function call auxiliary functions to */
/* check if its possible move up and down */
/* If its possible to move, so where the player was */
/* will be fill with empty space */

static	int	up_down(t_root *game, int key)
{
	int	x;
	int	y;
	int	check;

	x = game->player_x;
	y = game->player_y;
	if (key == 13)
	{
		y--;
		if (game->map[y][x] == '1')
			return (0);
		check = valid_move(game, x, y);
		if (!check)
			return (0);
		game->map[y + 1][x] = '0';
	}
	else if (key == 1)
	{
		y++;
		if (game->map[y][x] == '1')
			return (0);
		check = valid_move(game, x, y);
		if (!check)
			return (0);
		game->map[y - 1][x] = '0';
	}
	printf("Steps Taken: %i\n Potions Left: %i\n",
		game->step_counter, game->potions);
	return (1);
}

/* This function call auxiliary functions to check */
/* if its possible move left and right */
/* If its possible to move, so where the player was */
/* will be fill with empty space */

static	int	left_right(t_root *game, int key)
{
	int	x;
	int	y;
	int	check;

	x = game->player_x;
	y = game->player_y;
	if (key == 0)
	{
		x--;
		if (game->map[y][x] == '1')
			return (0);
		check = valid_move(game, x, y);
		if (!check)
			return (0);
		game->map[y][x + 1] = '0';
	}
	else if (key == 2)
	{
		x++;
		if (game->map[y][x] == '1')
			return (0);
		check = valid_move(game, x, y);
		if (!check)
			return (0);
		game->map[y][x - 1] = '0';
	}
	printf("Stpes Taken: %i\n Potions Left: %i\n",
		game->step_counter, game->potions);
	return (1);
}

static	int	valid_move(t_root *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->potions != 0)
			return (0);
		printf("\e[31m\e[1m\nCongratulations You Win! \e[0m \n");
		free_exit(game);
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		game->step_counter++;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		game->potions--;
		game->step_counter++;
	}
	return (1);
}
