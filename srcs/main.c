/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:31:44 by ybenoit           #+#    #+#             */
/*   Updated: 2017/09/15 10:18:44 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	secure_free2(t_env **e, char ***ret, t_node ***tree, int ***ways)
{
	int i = 0;

	while (i < e[0]->way + 1)
	{
		free(ways[0][i]);
		i++;
	}
	free(ways[0]);
	free(e[0]->empty);
	i = 0;
	while (i < e[0]->nb_room)
	{
		free(tree[0][i]->next);
		free(tree[0][i]);
		i++;
	}
	free(tree[0]);
}

static void	secure_free(t_env **e, char ***ret, t_node ***tree, int ***ways)
{
	int i;

	i = 0;
	while (i < e[0]->nb_room)
	{
		free(e[0]->all_r[i].name);
		i++;
	}
	free(e[0]->all_r);
	i = 0;
	while (i < e[0]->nb_room)
	{
		free(e[0]->tab[i]);
		i++;
	}
	free(e[0]->tab);
	if (tree[0] && ways[0])
		secure_free2(e, ret, tree, ways);
	if (*e)
		free(*e);
}

static void		print_file(char **file)
{
	char **tmp;

	tmp = file;
	while (*tmp)
	{
		ft_printf("%s\n", *tmp);
		free(*tmp);
		tmp++;
	}
	free(file);
	ft_printf("\n");
}

static void	lem_in(t_env *e, char **ret, t_node **tree, int **ways)
{
	print_file(ret);
	e->nb_way_to_use = find_optiway(e, ways);
	if (e->d_m)
		display_map(e);
	if (e->p_w)
		print_way(ways, e);
	move_ant(e, ways, tree);
}

void		error_code(t_env *e, char **ret, t_node **tree
		, int **ways)
{
	printf("Error\n");
	secure_free(&e, &ret, &tree, &ways);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_env	*e;
	char	**ret;
	t_node	**tree;
	int		**ways;

	ret = save_file(ret);
	if (!ret)
		return (ft_printf("Error: bad input\n"));
	e = fill_env(e, ret);
	if (!e || e->start == -1 || e->end == -1 || e->start == e->end)
			error_code(e, ret, NULL, NULL);
	tree = map_tree_init(e);
	ways = give_way(tree, e);
	if (e->way == 0)
			error_code(e, ret, tree, ways);
	sort_tab(ways);
	if (argc == 2)
	{
		if ((analyse_ac(e, argv[1] + 1) != 0 && argv[1][0] == '-')
				|| e->error_code)
			error_code(e, ret, tree, ways);
	}
	lem_in(e, ret, tree, ways);
	secure_free(&e, &ret, &tree, &ways);
	return (0);
}
