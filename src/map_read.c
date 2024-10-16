/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszlicht <mszlicht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:43:12 by mszlicht          #+#    #+#             */
/*   Updated: 2024/05/22 13:37:08 by mszlicht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_root *root, char *file)
{
	map_width(root, file);
	map_height(root, file);
	map_isvalid(root, file);
	root->game->coll
		= (t_coord *)malloc(sizeof(t_coord) * root->game->count_coll);
	if (root->game->coll == 0)
	{
		free(file);
		root_destroy(root, "map_parsing(): malloc()", errno);
	}
	root->game->map = (int **)malloc(sizeof(int *) * root->game->height);
	if (root->game->map == 0)
	{
		free(file);
		root_destroy(root, "map_parsing(): malloc()", errno);
	}
	map_parsing(root, file);
}
