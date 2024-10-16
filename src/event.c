/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszlicht <mszlicht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:43:12 by mszlicht          #+#    #+#             */
/*   Updated: 2024/05/22 13:37:08 by mszlicht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_root *root)
{
	if (keycode == 65307)
	{
		ft_printf("\nYou closed the game by ESC");
		root_destroy(root, 0, 0);
	}
	if (keycode == 119)
		root->game->player_up = 1;
	if (keycode == 115)
		root->game->player_down = 1;
	if (keycode == 97)
		root->game->player_left = 1;
	if (keycode == 100)
		root->game->player_right = 1;
	update(root);
	return (0);
}

int	key_release(int keycode, t_root *root)
{
	if (keycode == 119)
		root->game->player_up = 0;
	if (keycode == 115)
		root->game->player_down = 0;
	if (keycode == 97)
		root->game->player_left = 0;
	if (keycode == 100)
		root->game->player_right = 0;
	update(root);
	return (0);
}

int	destroy_hook(int keycode, t_root *root)
{
	(void)keycode;
	(void)root;
	root_destroy(0, 0, 0);
	return (0);
}
