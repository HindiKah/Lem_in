/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:03:15 by ybenoit           #+#    #+#             */
/*   Updated: 2017/05/09 16:30:37 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			**give_way(t_node **tree, t_env *e)
{
	int		**ret;
	int		ways;
	int		i;

	i = 0;
	e->way = 0;
	ret = (int**)malloc(sizeof(int*) * count_neighbour(e, e->start));
	while (ret[i] || !i)
	{
		search_node(tree, e, e->start)->passed = 0;
		ret[i] = (int*)malloc(sizeof(int) * (e->nb_room + 1));
		ret[i][0] = e->start;
		ret[i][1] = -1;
		ret[i] = search_way(search_node(tree, e, e->start), e, ret[i]);
		i++;
	}
	return (ret);
}

int				*search_way(t_node *start, t_env *e, int *ret)
{
	t_node	*to_visit;
	int		i;

	i = 0;
	if (!*start->next)
		return (NULL);
	to_visit = start->next[0];
	start->passed = 1;
	add_end_tab(ret, to_visit->name);
	if (to_visit->name == e->end)
		return (ret);
	while (start->next[i])
	{
		if (to_visit->passed != 1)
			search_way(to_visit, e, ret);
		i++;
		to_visit = start->next[i];
	}
	return (NULL);
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
