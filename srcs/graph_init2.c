/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:17:56 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/07 14:37:48 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_neighbour(t_env *e, int node)
{
	int i;
	int ret;

	i = 0;
	ret = 0				;
	while (i < e->nb_room)
	{
		if (e->tab[node][i])
			ret++;
		i++;
	}
	return (ret > 0 ? ret : -1);
}

int		*add_tab_value(int *tab, int n)
{
	int i;
	int *ret;

	i = 0;
	while (tab[i] != -1)
		i++;
	ret = (int*)malloc(sizeof(int) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (tab[i] != -1)
	{
		ret[i] = tab[i];
		ft_printf("tab[%d] = %d\n", i, ret[i]);
		i++;
	}
	ret[i++] = n;
	ret[i] = -1;
	free(tab);
	tab = ret;
	return (tab);
}
