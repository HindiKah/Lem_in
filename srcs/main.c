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
			else if (str[i] == 'p')
				e->p_w = 1;
			else if (str[i] == 'd')
				e->d_m = 1;
			i++;
		}
		else
			return (ft_printf("%s", USAGE));
	}
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
	if (!e || e->start == -1 || e->end == -1)
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
	ft_printf("\nMAP:\n");
	ft_printf("\n");
	ft_printf("    There is %d ants in an %d pieces home, they want to go from room nb'%d' to room nb'%d'\n\n", e->ant_n, e->nb_room, e->start, e->end);
	i = 0;
	ft_printf("Ant_home Matrice:\n\n");
	ft_printf("       ");
	while (i < e->nb_room)
		ft_printf("%-3s", e->all_r[i++][1]); 
	i = 0;
	ft_printf("\n");
	while (i < e->nb_room)
	{
		j = 0;
		ft_printf("    %-3s", e->all_r[i][1]);
		while (j < e->nb_room)
			ft_printf("%-3d", e->tab[i][j++]);
		ft_printf("\n");
		i++;
	}
}

void			print_tab(int *tab, t_env *e)
{
	int i;

	i = 0;
	while (tab[i + 1] != -1)
	{
		ft_printf("%s -> ", e->all_r[tab[i]][1]);
		i++;
	}
	ft_printf("%s", e->all_r[tab[i]][1]);
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
