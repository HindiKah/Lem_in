/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 14:57:53 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/29 15:20:12 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			move_ant(t_env *e, int **ways, t_node **tree)
{
	int						end_ants;
	int						i;
	unsigned long int		iter;

	iter = 0;
	end_ants = 0;
	init_tree_ants(e, tree);
	while (end_ants != e->ant_n)
	{
		i = 0;
		while (i < e->nb_way_to_use)
		{
			move_next(ways[i], e, tree, i);
			i++;
		}
		ft_printf("\n");
		end_ants = tree[e->end]->nb_ant;
		iter++;
	}
	if (e->nb_iter == 1)
	{
		ft_printf("\nThere is %ld itereration(s) needed to ", iter);
		ft_printf("complete the map using %d way(s)\n",
				e->nb_way_to_use);
	}
}

int				find_optiway(t_env *e, int **ways)
{
	int ant;
	int i;

	ant = 0;
	i = 0;
	if (e->multi == 0)
		return (1);
	while (ways[i][0] != -666 && (ant += way_len(ways[i])) <= e->ant_n)
		i++;
	if (i <= 0 && e->way)
		i = 1;
	if (e->multi == 1 && e->force_way_use == 1)
	{
		if (e->nb_way_to_use > e->way)
			return (i);
		else
			return (e->nb_way_to_use);
	}
	return (i);
}

static void		move_next_cut(t_node **tree, t_env *e, int i, int *way)
{
	tree[way[i + 1]]->ant_name = tree[way[i]]->ant_name;
	if (tree[way[i]]->ant_name != -1)
	{
		ft_printf("L%d-%s ",
				tree[way[i]]->ant_name,
				e->all_r[way[i + 1]].name);
		tree[way[i + 1]]->nb_ant++;
	}
}

void			move_next(int *way, t_env *e, t_node **tree, int way_n)
{
	int i;

	i = 0;
	while (way[i + 1] != -1)
		i++;
	i--;
	while (i - 1 >= 0)
	{
		move_next_cut(tree, e, i, way);
		i--;
	}
	if (tree[e->start]->nb_ant <= 0)
		tree[way[1]]->ant_name = -1;
	if (tree[e->start]->nb_ant != 0)
	{
		ft_printf("L%d-%s ", tree[e->start]->ant_name,
				e->all_r[way[1]].name);
		tree[way[1]]->ant_name = tree[e->start]->ant_name;
		tree[way[1]]->nb_ant++;
		tree[e->start]->nb_ant--;
		tree[e->start]->ant_name++;
	}
}

void			init_tree_ants(t_env *e, t_node **tree)
{
	int i;

	i = 0;
	while (i < e->nb_room)
	{
		tree[i]->ant_name = -1;
		i++;
	}
	tree[e->start]->nb_ant = e->ant_n;
	tree[e->start]->ant_name = 1;
	tree[e->end]->nb_ant = 0;
	tree[e->end]->ant_name = -1;
}
