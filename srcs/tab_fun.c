/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:30:13 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/27 14:57:28 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			way_len(int *tab)
{
	int i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i] != -1)
		i++;
	if (i == 1)
		return (123456789);
	return (i);
}

void		del_unseless(int **tab)
{
	int i;

	i = 0;
	while (tab[i][0] != -666 && tab[i][1] != -1)
		i++;
	tab[i][0] = -666;
}

void		sort_tab(int **tab)
{
	int i;
	int	tmp;
	int	place;
	int max;

	max = 0;
	i = 0;
	place = 0;
	while (tab[place++][0] != -666)
		max++;
	place = 0;
	while (place + 1 < max)
	{
		i = place;
		tmp = i + 1;
		while (i < max)
		{
			tmp = (way_len(tab[i]) < way_len(tab[tmp])) ?
				i : tmp;
			i++;
		}
		switch_tab(tab, place, tmp);
		place++;
	}
	del_unseless(tab);
}

void		switch_tab(int **tab, int a, int b)
{
	int *tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}
