/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:31:44 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/29 15:19:42 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	secure_free(t_env **e, char ***ret, t_node ***tree, int ***ways)
{
	int i;

	i = -1;
	while (ret[0][i])
		free(ret[0][i++]);
	free(*ret);
	i = 0;
	while (i < e[0]->nb_room)
	{
		free(tree[0][i]);
		i++;
	}
	free(tree[0]);
	i = 0;
	while (i < e[0]->way)
	{
		free(ways[0][i]);
		i++;
	}
	free(e[0]->all_r);
	free(e[0]->tab);
	if (*e)
		free(*e);
}

static void	lem_in(t_env *e, char **ret, t_node **tree, int **ways)
{
	e->nb_way_to_use = find_optiway(e, ways);
	if (e->d_m)
		display_map(e);
	if (e->p_w)
		print_way(ways, e);
	move_ant(e, ways, tree);
}

int			main(int argc, char **argv)
{
	t_env	*e;
	char	**ret;
	t_node	**tree;
	int		**ways;

	ret = save_file(ret);
	if (!ret)
		return (ft_printf("ERROR ON INPUT\n"));
	e = fill_env(e, ret);
	if (!e || e->start == -1 || e->end == -1 || e->start == e->end)
		return (ft_printf("ERROR ON MAP\n"));
	tree = map_tree_init(e);
	ways = give_way(tree, e);
	if (e->way == 0)
		return (ft_printf("NO WAY AVAIBLE\n"));
	sort_tab(ways);
	if (argc == 2)
	{
		if (analyse_ac(e, argv[1] + 1) != 0 && argv[1][0] == '-')
			return (0);
	}
	lem_in(e, ret, tree, ways);
	secure_free(&e, &ret, &tree, &ways);
	return (0);
}
