#include "../includes/lem_in.h"

void			move_ant(t_env *e, int **ways, t_node **tree)
{
	int		end_ants;
	int		i;

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
	}
}

int				find_optiway(t_env *e, int **ways)
{
	int ant;
	int i;

	ant = 0;
	i = 0;
	while (ways[i][0] != -666 && (ant += way_len(ways[i])) <= e->ant_n)
		i++;
	if (e->multi == 1 && e->force_way_use == 1)
	{
		if (e->nb_way_to_use > e->way)
			return (i);
		else
			return (e->nb_way_to_use);
	}
	return (i);
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
			tree[way[i + 1]]->ant_name = tree[way[i]]->ant_name;
		if (tree[way[i]]->ant_name != -1)
		{
			ft_printf("L%d-%s ", tree[way[i]]->ant_name, e->all_r[way[i + 1]][1]);
			tree[way[i + 1]]->nb_ant++;
		}
		i--;
	}
	if (tree[e->start]->nb_ant <= 0)
		tree[way[1]]->ant_name = -1;
	if (tree[e->start]->nb_ant != 0)
	{
		ft_printf("L%d-%s ", tree[e->start]->ant_name, e->all_r[way[1]][1]);
		tree[way[1]]->ant_name = tree[e->start]->ant_name;
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
