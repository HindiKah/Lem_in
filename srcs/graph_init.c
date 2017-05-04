#include "../includes/lem_in.h"

t_node			*map_tree_init(t_env *e)
{
	t_node	*ret;
	int		i;

	i = 0;
	ft_printf(" count = %d\n", count_neighbour(e, 7));
	ret = (t_node*)malloc(sizeof(t_node) * (count_neighbour(e, e->start) + 1));
	e->pass = (int*)malloc(sizeof(int) * 2);
	e->way = 0;
	e->pass[0] = e->start;
	e->pass[1] = -1;
	ret->depth = 0;
	ret->from = -1;
	ret->previous = NULL;
	ret->name = e->start;
	return (ret);
}

t_node			*build_tree(t_env *e, t_node *node)
{
	t_node *start;
	int i;
	int y;

	i = 0;
	y = e->start;
	start = node;
	node->name = e->start;
	while (i < e->nb_room)
	{
		if (e->tab[
	node->next = 
	}

	}

int				is_it_passed(int *tab, int node)
{
	int i;

	i = 0;
	while (tab[i] != -1)
	{
		if (tab[i] == node)
			return (1);
		i++;
	}
	return (0);
}

int				count_neighbour(t_env *e, int node)
{
	int i;
	int ret;

	i = 0;
	while (i < e->nb_room)
	{
		if (e->tab[node][i])
			ret++;
		i++;
	}
	ret--;
	return (ret);
}

int				*add_tab_value(int *tab, int n)
{
	int i;
	int *ret;

	i = 0;
	while (tab[i] != -1)
		i++;
	ret = (int*)malloc(sizeof(int) * (i + 1));
	if (!ret)
		return NULL;
	i = 0;
	while (tab[i] != -1)
	{
		ret[i] = tab[i];
		ft_printf("tab[%d] = %d\n", i, ret[i]);
		i++;
	}
	ret[i++] = n;
	ret[i] = -1;
	free(tab);
	tab = ret;
	return (tab);
}
