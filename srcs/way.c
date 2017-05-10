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
	search_node(tree, e, e->start)->passed = 1;
	ret = (int**)malloc(sizeof(int*) * count_neighbour(e, e->start));
	while (ret[i] || !i)
	{
		ret[i] = (int*)malloc(sizeof(int) * (e->nb_room + 1));
		ret[i][0] = e->start;
		ret[i][1] = -1;
		ret[i] = search_way(tree, search_node(tree, e, e->start), e, ret[i]);
		i++;
	}
	return (ret);
}

int				*search_way(t_node **tree, t_node *start, t_env *e, int *ret)
{
	t_node	*to_visit;
	int		i;

	i = 0;
	if (!start)
		return (NULL);
	//print_passed(tree, e);
	start->passed = 1;
	while (start->next[i])
	{
		to_visit = start->next[i];
	//ft_printf("name of start is %d\n", start->name);
	//ft_printf("name of to_visit is %d -> passed = %d\n", to_visit->name, to_visit->passed);
		if (to_visit->name == e->end)
		{
	ft_printf("END OF TREE[%d] name of to_visit is %d -> passed = %d\n", e->end,to_visit->name, to_visit->passed);
			add_end_tab(ret, to_visit->name);
			print_tab(ret);
			return (ret);
		}
		else if (to_visit->passed != 1)
		{
	ft_printf("NO PASSED name of to_visit is %d -> passed = %d\n", to_visit->name, to_visit->passed);
			add_end_tab(ret, to_visit->name);
			search_way(tree, to_visit, e, ret);
		}
		i++;
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
