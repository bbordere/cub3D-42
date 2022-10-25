/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:13:55 by tdesmet           #+#    #+#             */
/*   Updated: 2022/10/25 14:15:09 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "struct.h"

/* -------------------------------------------------------------------------- */
/*                        FILE = src/parsing/atorgb.c                         */
/* -------------------------------------------------------------------------- */
int			ft_check_is_rgb(char *line, char c, int *check);
int			ft_atorgb(char *str);

/* -------------------------------------------------------------------------- */
/*                       FILE = src/parsing/fill_map.c                        */
/* -------------------------------------------------------------------------- */
int			*ft_fill_line(t_game *game, char *line, int *map);
int			**ft_fill_map(t_game *game, int **map, char *line, int fd);
int			ft_copy_map(t_game *game, int **map, char *path);

/* -------------------------------------------------------------------------- */
/*                        FILE = src/parsing/parsing.c                        */
/* -------------------------------------------------------------------------- */
size_t		ft_get_texture_index( char *id);
int			ft_check_valid_path(t_game *game, char *line,
				char *str);
char		*ft_getpath( char *line);
int			ft_check_ext_file(char *str, char *ext);
int			ft_parsing(t_game *game, int argc, char **argv);

/* -------------------------------------------------------------------------- */
/*                     FILE = src/parsing/check_border.c                      */
/* -------------------------------------------------------------------------- */
int			ft_get_wall_char(t_game *game, int x, int y);
int			ft_check_border(t_game *game, int **map);
int			ft_check_is_a_border(t_game *game, int **map, int x, int y);

/* -------------------------------------------------------------------------- */
/*                      FILE = src/parsing/err_parsing.c                      */
/* -------------------------------------------------------------------------- */
void		ft_err_file_name(int argc);
void		ft_get_error_msg(int error);
void		ft_err_in_file(t_game *game, int error, int line);
void		ft_err_copy_map(t_game *game);
void		ft_err_bordere(int x, int y);

/* -------------------------------------------------------------------------- */
/*                       FILE = src/parsing/check_map.c                       */
/* -------------------------------------------------------------------------- */
int			ft_check_map(t_game *game, char *line, t_check *check,
				int line_cnt);
int			ft_is_valid_map_line(t_game *game, char *line);
int			ft_check_spawn(t_game *game, char *line, int spawn, int line_cnt);
t_check		*ft_init_check(t_check *check);
int			ft_check_file(t_game *game, int fd, t_check *check);

/* -------------------------------------------------------------------------- */
/*                    FILE = src/parsing/check_map_head.c                     */
/* -------------------------------------------------------------------------- */
int			ft_check_map_head(t_game *game, char *line, t_check *check);
int			ft_check_is_head(char *str);
int			ft_check_valid_head(t_check *check);

#endif
