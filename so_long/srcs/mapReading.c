/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapReading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:59:16 by wwang             #+#    #+#             */
/*   Updated: 2022/04/12 16:29:11 by wwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_width(char *str);
static int	addnewline(t_root *game, char *line);

int	read_map(t_root *game, char **argv)
{
	char	*read;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		read = get_next_line(game->fd);
		if (!addnewline(game, read))
			break ;
	}
	close (game->fd);
	game->map_width = get_width(game->map[0]);
	return (1);
}

static	int	addnewline(t_root *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->map_height++;
	temp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	temp[game->map_height] = NULL;
	while (i < game->map_height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

static	int	get_width(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == '\n')
		i--;
	return (i);
}
