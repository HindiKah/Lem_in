#include "../includes/lem_in.h"

t_node			**map_tree_init(t_env *e)
{
	t_node	**tree;
	int		i;

	i = 0;
	tree = (t_node**)malloc(sizeof(t_node*) * (e->nb_room + 1));
	while (i < e->nb_room)
	{
		tree[i] = init_node(tree[i], e, i);
		i++;
	}
	i = 0;
	while (i < e->nb_room)
	{
		tree[i] = link_node(tree[i], e, tree);
		i++;
	}
	return (tree);
}

t_node			*init_node(t_node *node, t_env *e, int n)
{
	node = (t_node*)malloc(sizeof(t_node));
	node->name = n;
	node->next = (t_node**)malloc(sizeof(t_node*) * (count_neighbour(e, n) + 1));
	node->passed = 0;
	return (node);
}

t_node			*link_node(t_node *node, t_env *e, t_node **tree)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (i < e->nb_room)
	{
		if (e->tab[node->name][i])
		{
			node->next[y] = search_node(tree, e, i);
			y++;
		}
		i++;
	}
	node->next[y] = NULL;
	return (node);
}

t_node			*search_node(t_node **tree, t_env *e, int node)
{
	int i;

	i = 0;
	while (i < e->nb_room && tree[i])
	{
		if (tree[i]->name == node)
			return (tree[i]);
		i++;
	}
	return (NULL);
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
	ret = 0;
	while (i < e->nb_room)
	{
		if (e->tab[node][i])
			ret++;
		i++;
	}
	return (ret > 0 ? ret : -1);
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
