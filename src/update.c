/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszlicht <mszlicht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:43:12 by mszlicht          #+#    #+#             */
/*   Updated: 2024/05/22 13:37:08 by mszlicht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	had_move(t_root *root, int x, int y)
{
	if (root->game->player.x != x || root->game->player.y != y)
	{
		root->game->player_move++;
		ft_printf("\nSteps taken: ");
		ft_putnbr_fd(root->game->player_move, 1);
		ft_printf(" 👻\nBones: ");
		ft_putnbr_fd(root->game->player_coll, 1);
		ft_printf("/");
		ft_putnbr_fd(root->game->count_coll, 1);
		ft_printf(" 🦴");
		ft_putendl_fd("", 1);
	}
}

static void	iscollectable(t_root *root)
{
	int				k;

	k = 0;
	while (k < root->game->count_coll)
	{
		if (root->game->coll[k].x == root->game->player.x
			&& root->game->coll[k].y == root->game->player.y)
		{
			root->game->coll[k].x = -1;
			root->game->coll[k].y = -1;
			root->game->player_coll++;
		}
		k++;
	}
}

void	update(t_root *root)
{
	int				x;
	int				y;

	x = root->game->player.x;
	y = root->game->player.y;
	if (root->game->player_up != 0)
		move_up(root, x, y);
	else if (root->game->player_down != 0)
		move_down(root, x, y);
	else if (root->game->player_left != 0)
		move_left(root, x, y);
	else if (root->game->player_right != 0)
		move_right(root, x, y);
	had_move(root, x, y);
	iscollectable(root);
	draw(root);
	if (root->game->exit.x == root->game->player.x
		&& root->game->exit.y == root->game->player.y)
		if (root->game->count_coll == root->game->player_coll)
		{
			ft_printf("\nYou have won! Congrats! 🏆");
			root_destroy(root, 0, 0);
		}
}
