/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:03:15 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/29 15:23:59 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				**give_way(t_node **tree, t_env *e)
{
	int		**ret;
	t_node	*tmp;
	int		i;
	int		i_way;

	i = -1;
	i_way = count_neighbour(e, e->end);
	e->way = 0;
	search_node(tree, e, e->start)->passed = 1;
	ret = (int**)malloc(sizeof(int*) * (i_way + 1));
	while (++i < i_way)
	{
		tmp = search_node(tree, e, e->start);
		search_node(tree, e, e->end)->passed = 0;
		ret[i] = (int*)malloc(sizeof(int) * (e->nb_room + 1));
		ret[i][0] = e->start;
		ret[i][1] = -1;
		ret[i] = search_way(tree, &tmp, e, &ret[i]);
		del_link(tree, ret[i], e);
		if (!ret[i])
			break ;
	}
	ret[i] = (int*)malloc(sizeof(int));
	ret[i][0] = -666;
	return (ret);
}

int				*search_way(t_node **tree, t_node **start, t_env *e, int **ret)
{
	t_node	*to_visit;
	int		i;

	i = -1;
	if (!start)
		return (NULL);
	if (search_node(tree, e, e->end)->passed == 1)
		return (*ret);
	start[0]->passed = 1;
	while (start[0]->next[++i])
	{
		to_visit = start[0]->next[i];
		if (to_visit->name == e->end && to_visit->passed != 1 && (e->way++))
		{
			to_visit->passed = 1;
			add_end_tab(*ret, to_visit->name);
			return (*ret);
		}
		else if (to_visit->passed != 1 && to_visit->name != -1)
		{
			if (give_last_tab(*ret) != e->end)
				add_end_tab(*ret, to_visit->name);
			search_way(tree, &to_visit, e, ret);
		}
	}
	return (*ret);
}

int				*add_end_tab(int *ret, int n)
{
	int		i;

	i = 0;
	while (ret[i] != -1)
		i++;
	ret[i] = n;
	i++;
	ret[i] = -1;
	return (ret);
}

int				give_last_tab(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != -1)
		i++;
	if (i >= 1)
		return (tab[i - 1]);
	else
		return (-1);
}

void			del_link(t_node **tree, int *tab, t_env *e)
{
	int i;
	int j;

	i = 0;
	while (tab[i + 1] != -1)
	{
		j = 0;
		while (tree[tab[i]]->next[j] && tree[tab[i]]->next[j]->name
				!= tab[i + 1])
			j++;
		if (tree[tab[i]]->next[j])
			tree[tab[i]]->next[j] = e->empty;
		i++;
	}
	while (i > 0)
	{
		j = 0;
		while (tree[tab[i]]->next[j] && tree[tab[i]]->next[j]->name
				!= tab[i - 1])
			j++;
		if (tree[tab[i]]->next[j])
			tree[tab[i]]->next[j] = e->empty;
		i--;
	}
}
