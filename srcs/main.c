/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:31:44 by ybenoit           #+#    #+#             */
/*   Updated: 2017/05/15 14:00:33 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
void		display_map(t_env *e);
int			analyse_ac(t_env *e, char *str)
{
	if (str[0] != '-' && str[1] == 'm')
		return (ft_printf("%s", USAGE));
	else
		e->multi = 1;
	if (str[2] && ft_atoi(str + 2) > 0)
	{
		e->force_way_use = 1;
		e->nb_way_to_use = ft_atoi(str + 2);
	}
		e->p_w = ft_strchr(str, 'p') ? 1 : 0;
		e->d_m = ft_strchr(str, 'd') ? 1 : 0;
		return (ft_printf("%s", USAGE));
	return (0);
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
	if (argc == 2)
	{
		if (analyse_ac(e, argv[1]) != 0)
			return (0);
	}
	tree = map_tree_init(e);
	ways = give_way(tree, e);
	sort_tab(ways);
	if (e->d_m)
		display_map(e);
	if (e->p_w)
		print_way(ways, e);
	move_ant(e, ways, tree);
	return (0);
}
void			display_link(t_node **tree, t_env *e)
{
int i;
	i = 0;
	int y = 0;
	while (i < e->nb_room)
	{
		ft_printf("node[%d] is link whith ", i);
		y = 0;
		while (tree[i]->next[y])
		{
			ft_printf(" %d ", tree[i]->next[y]->name);
			y++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void		display_map(t_env *e)
{
	int i;
	int j;

	i = 0;
	ft_printf("\t\tMAP\n");
	ft_printf("\n");
	ft_printf("ant_n -> %d\nnb_room -> %d\nstart -> room n'%d'\nend -> room n'%d'\n", e->ant_n, e->nb_room, e->start, e->end);
	ft_printf("multi = %d\n nb_way_to_use = %d\n e->way = %d\n\n", e->multi, e->nb_way_to_use, e->way);
	i = 0;
	ft_printf("  ");
	while (i < e->nb_room)
		ft_printf(" %s ", e->all_r[i++][1]); 
	i = 0;
	ft_printf("\n");
	while (i < e->nb_room)
	{
		j = 0;
		ft_printf("%s ", e->all_r[i][1]);
		while (j < e->nb_room)
			ft_printf(" %d ", e->tab[i][j++]);
		ft_printf("\n");
		i++;
	}
		ft_printf("\n");
}

void			print_tab(int *tab, t_env *e)
{
	int i;

	i = 0;
	/*while (tab[i] != -1)
	{
		ft_printf("%3d  ", i);
		i++;
	}
	ft_printf("\n");*/
	i = 0;
	//ft_printf("%s", "           ");
	while (tab[i] != -1)
	{
		ft_printf("%3s  ", e->all_r[tab[i]][1]);
		i++;
	}
	i = 0;
	ft_printf("%s", "\n           ");
	while (tab[i] != -1)
	{
		ft_printf("%3d  ", tab[i]);
		i++;
	}
	ft_printf("\n\n\n");
}

void			print_way(int **tab, t_env *e)
{
	int i;

	i = 0;
	while (tab[i][0] > -1)
	{
		ft_printf("\n\nWAY[%d] ->> ", i);
		print_tab(tab[i++], e);
	}
}

void			print_passed(t_node **tree, t_env *e)
{
	int i;
	i = 0;
	int y = 0;
	while (i < e->nb_room)
	{
		ft_printf("node[%d] passed = %d ", i, tree[i]->passed);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}
