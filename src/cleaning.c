/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:35:52 by bbordere          #+#    #+#             */
/*   Updated: 2022/10/21 16:09:50 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_assets(t_assets *assets, void *mlx)
{
	if (assets->wall_e)
		mlx_destroy_image(mlx, assets->wall_e->mlx_img);
	if (assets->wall_n)
		mlx_destroy_image(mlx, assets->wall_n->mlx_img);
	if (assets->wall_s)
		mlx_destroy_image(mlx, assets->wall_s->mlx_img);
	if (assets->wall_w)
		mlx_destroy_image(mlx, assets->wall_w->mlx_img);
	free(assets->wall_e);
	free(assets->wall_n);
	free(assets->wall_s);
	free(assets->wall_w);
	free(assets);
}

void	ft_free_player(t_player *player)
{
	if (player->dir)
		free(player->dir);
	if (player->pos)
		free(player->pos);
	free(player);
}

void	ft_free_ray(t_ray *ray)
{
	if (ray->dir)
		free(ray->dir);
	if (ray->pos)
		free(ray->pos);
	free(ray);
}

void	ft_free_map(t_game *game, int i)
{
	if (game->map->map)
		while (i >= 0)
			free(game->map->map[i--]);
	free(game->map->map);
	free(game->map);
}

int	ft_free_all(t_game *game)
{
	if (game->ray)
		ft_free_ray(game->ray);
	if (game->assets)
		ft_free_assets(game->assets, game->mlx);
	if (game->player)
		ft_free_player(game->player);
	if (game->plane)
		free(game->plane);
	if (game->textures_path)
		ft_free_textures(game);
	if (game->map)
		ft_free_map(game, game->map->height - 1);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->img)
	{
		mlx_destroy_image(game->mlx, game->img->mlx_img);
		free(game->img);
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}
