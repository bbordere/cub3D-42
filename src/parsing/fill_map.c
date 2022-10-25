/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:21:01 by tdesmet           #+#    #+#             */
/*   Updated: 2022/10/20 11:15:41 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*ft_fill_line(t_game *game, char *line, int *map)
{
	int	y;

	y = 0;
	while (y < game->map->width)
	{
		if (!line[y] || line[y] == '\n')
			while (y < game->map->width)
				map[y++] = -1;
		else if (line[y] == ' ')
			map[y] = -1;
		else if (ft_strchr("WENS", line[y]))
			map[y] = 0;
		else
			map[y] = line[y] - '0';
		y++;
	}
	return (map);
}

int	**ft_fill_map(t_game *game, int **map, char *line, int fd)
{
	int	x;

	x = 0;
	while (x < game->map->height)
	{
		map[x] = ft_calloc(game->map->width, sizeof(int));
		if (!map[x])
			return (ft_err_copy_map(game), NULL);
		map[x] = ft_fill_line(game, line, map[x]);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		x++;
	}
	close(fd);
	if (x != game->map->height - 1)
		return (NULL);
	return (map);
}

int	ft_copy_map(t_game *game, int **map, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (ft_free_all(game), 0);
	while (ft_check_is_head(line))
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (ft_free_all(game), 0);
	}
	map = ft_fill_map(game, map, line, fd);
	if (!map)
		return (0);
	return (1);
}
