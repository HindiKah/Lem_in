/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:58:01 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/27 14:55:48 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				count_room(char **map_str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (map_str[i] && !ft_strchr(map_str[i], '-'))
	{
		if (map_str[i][0] != '#')
			ret++;
		i++;
	}
	return (ret);
}

t_env			*init_env(t_env *e)
{
	e = (t_env*)malloc(sizeof(t_env));
	e->ant_n = 0;
	e->start = -1;
	e->end = -1;
	e->tab = NULL;
	e->all_r = NULL;
	e->force_way_use = 0;
	e->nb_way_to_use = 1;
	e->way = 0;
	e->multi = 0;
	return (e);
}

t_env			*fill_env(t_env *e, char **map_str)
{
	int i;

	i = 0;
	e = init_env(e);
	while (map_str[i][0] == '#' && map_str[i])
		i++;
	if (!check_nbant(map_str[i]))
	{
		ft_putstr("NB_ANT INCORRECT -> ");
		return (NULL);
	}
	e->ant_n = ft_atoi(map_str[i++]);
	e = init_room(e, map_str + i);
	if (!e)
	{
		ft_putstr("DECLATION ROOM PROBLEM -> ");
		return (NULL);
	}
	while (map_str[i] && !ft_strchr(map_str[i], '-'))
		i++;
	e->tab = init_tab(e, map_str);
	e->empty = (t_node*)malloc(sizeof(t_node));
	e->empty->name = -1;
	return (e);
}

t_env			*init_room(t_env *e, char **map_str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	e->nb_room = count_room(map_str);
	e->all_r = (char***)malloc(sizeof(char**) * e->nb_room);
	while (map_str[i] && !ft_strchr(map_str[i], '-'))
	{
		if (!e)
			return (NULL);
		if (map_str[i][0] != '#' && ft_strchr(AUTHORIZE, map_str
					[i][0]))
		{
			if (!check_droom(map_str[i]))
				return (NULL);
			e->all_r[j] = init_this_room(map_str[i], j);
			j++;
		}
		else if (map_str[i][0] == '#' && map_str[i][1] == '#')
			e = check_sharp(e, map_str + i, j);
		i++;
	}
	e->all_r[j] = NULL;
	return (e);
}
