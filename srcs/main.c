/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:31:44 by ybenoit           #+#    #+#             */
/*   Updated: 2017/05/04 17:21:33 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
void		display_map(t_env *e);

int			main(int argc, char **argv)
{
	t_env	*e;
	char	**ret;
	t_node	*tree;

	ret = save_file(ret);
	if (!ret)
		return (ft_printf("ERROR ON INPUT\n"));
	e = fill_env(e, ret);
	display_map(e);
	tree = map_tree_init(e);
	free(e);
	return (0);
}

void		display_map(t_env *e)
{
	int i;
	int j;

	i = 0;
	ft_printf("\t\tMAP\n");
	ft_printf("ant_n -> %d\nnb_room -> %d\nstart -> room n'%d'\nend -> room n'%d'\n\n", e->ant_n, e->nb_room, e->start, e->end);
	while (i < e->nb_room)
	{
		ft_printf("room nb %d is called %s\n", ft_atoi(e->all_r[i][0]), e->all_r[i][1]);
		i++;
	}
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
}

