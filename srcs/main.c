/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:31:44 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/27 15:03:34 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			analyse_ac(t_env *e, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(AUSAGE, str[i]))
		{
			if (str[i] == 'm')
			{
				e->multi = 1;
				if (str[i + 1] && ft_atoi(str + i + 1) > 0)
				{
					e->force_way_use = 1;
					e->nb_way_to_use = ft_atoi(str + i + 1);
				}
			}
			e->p_w = (str[i] == 'p' || e->p_w) ? 1 : 0;
			e->d_m = (str[i] == 'd' || e->d_m) ? 1 : 0;
			e->nb_iter = (str[i] == 'i' || e->nb_iter) ? 1 : 0;
			i++;
		}
		else
			return (ft_printf("%s", USAGE));
	}
	return (0);
}

void		secure_free(t_env *e, char **ret, t_node **tree, int **ways)
{
	int i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	i = 0;
	while (i < e->nb_room)
	{
		if (tree[i])
			free(tree[i]);
		i++;
	}
	if (tree)
		free(tree);
	i = 0;
	while (i < e->way)
	{
		free(ways[i]);
		i++;
	}
	if (e->tab)
		free(e->tab);
	if (e)
		free(e);
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
/*
int j = 0;
while (j < e->nb_room)
{
printf("e->>all_r[%d] = %d called %s\n", j, e->all_r[j].n_r, e->all_r[j].name);
j++;
}
*/
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
	e->nb_way_to_use = find_optiway(e, ways);
	if (e->d_m)
		display_map(e);
	if (e->p_w)
		print_way(ways, e);
	move_ant(e, ways, tree);
	secure_free(e, ret, tree, ways);
	return (0);
}

void		display_map(t_env *e)
{
	int i;
	int j;

	i = 0;
	ft_printf("\nMAP:\n");
	ft_printf("\n");
	i = 0;
	ft_printf("Ant_home Matrice:\n\n");
	ft_printf("       ");
	while (i < e->nb_room)
		ft_printf("%-3s", e->all_r[i++].name); 
	i = 0;
	ft_printf("\n");
	while (i < e->nb_room)
	{
		j = 0;
		ft_printf("    %-3s", e->all_r[i].name);
		while (j < e->nb_room)
			ft_printf("%-3d", e->tab[i][j++]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void			print_tab(int *tab, t_env *e)
{
	int i;

	i = 0;
	while (tab[i + 1] != -1)
	{
		ft_printf("%s -> ", e->all_r[tab[i]].name);
		i++;
	}
	ft_printf("%s", e->all_r[tab[i]].name);
}

void			print_way(int **tab, t_env *e)
{
	int i;

	i = 0;
	ft_printf("\nWay(s) to use:");
	while (i < e->nb_way_to_use && tab[i][0] != -666)
	{
		ft_printf("\n\n    WAY[%d] = [", i);
		print_tab(tab[i++], e);
		ft_printf("]");
		ft_printf("\n");
	}
	ft_printf("\n");
}
