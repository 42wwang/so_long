/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:34:26 by wwang             #+#    #+#             */
/*   Updated: 2022/04/16 19:08:04 by wwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *s, int c, size_t len);

int	main(int argc, char **argv)
{
	t_root	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_root));
	read_map(&game, argv);
	error_check(&game);
	game.mlxptr = mlx_init();
	game.winptr = mlx_new_window(game.mlxptr, (game.map_width * 40),
			(game.map_height * 40), "solong");
	img_init(&game);
	add_graphics(&game);
	mlx_key_hook(game.winptr, key_handler, &game);
	mlx_hook(game.winptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxptr);
}

int	free_exit(t_root *game)
{
	int	row;

	mlx_destroy_window(game->mlxptr, game->winptr);
	free(game->mlxptr);
	row = 0;
	while (row < game->map_height - 1)
		free(game->map[row++]);
	free(game->map);
	exit(0);
}

static	void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (len--)
		*str++ = (unsigned char)c;
	return (s);
}
