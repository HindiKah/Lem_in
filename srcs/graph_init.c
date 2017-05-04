#include "../includes/lem_in.h"

t_node			*map_tree_init(t_env *e)
{
	t_node	*ret;
	int		i;

	i = 0;
	ret = (t_node*)malloc(sizeof(t_node) * (count_neighbour(e, e->start) + 1));
	ret->depth = 0;
	ret->from = -1;
	ret->previous = NULL;
	ret->node = e->start;
	while (i < e->nb_room)
	{
		if (e->tab[e->start][i])
		{
			ret->next = give_next_node(e,NULL, i);
			ret->next++;
		}
		i++;
	}
	return (ret);
}

t_node			*give_next_node(t_env *e, t_node *prev, int node)
{
	t_node	*ret;
	int		i;

	i = 0;
	if (!is_it_passed(prev->pass, node) || node == e->end)
		return (NULL);
	ret = (t_node*)malloc(sizeof(t_node) * count_neighbour(e, node));
	while (i < e->nb_room)
	{
		if (e->tab[node][i] && !is_it_passed(prev->pass, i))
		{
			ret->next = give_next_node(e, prev, i);
			ret->pass = node;
			ret->previous = prev;
			ret->next++;
		}
		i++;
	}
	return (ret);
}

int				is_it_passed(int pass, int node)
{
	if (pass == node)
		return (0);
	return (1);
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

void			add_tab_value(int *tab, int n)
{
	int i;
	int *ret;

	i = 0;
	while (tab[i] != -1)
		i++;
	ret = (int*)malloc(sizeof(int) * (i + 1));
	if (!ret)
		return;
	i = 0;
	while (tab[i++] != -1)
		ret[i] = tab[i];
	ret[i++] = n;
	ret[i] = -1;
	free(tab);
	tab = ret;
}
