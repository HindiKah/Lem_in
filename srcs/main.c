/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:31:44 by ybenoit           #+#    #+#             */
/*   Updated: 2017/05/09 16:31:14 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
void		display_map(t_env *e);

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
	tree = map_tree_init(e);
	display_map(e);
	display_link(tree, e);
	ways = give_way(tree, e);
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
	ft_printf("ant_n -> %d\nnb_room -> %d\nstart -> room n'%d'\nend -> room n'%d'\n\n", e->ant_n, e->nb_room, e->start, e->end);
	while (i < e->nb_room)
	{
		ft_printf("room nb %d is called %s\n", ft_atoi(e->all_r[i][0]), e->all_r[i][1]);
		i++;
	}
	ft_printf("\n");
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

void			print_tab(int *tab)
{
	int i;

	i = 0;
	ft_printf("TAB ->> \n");
	while (tab[i] != -1)
	{
		ft_printf("%d ", i);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (tab[i] != -1)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
	ft_printf("\n");
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
