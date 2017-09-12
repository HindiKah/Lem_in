/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:58:01 by ybenoit           #+#    #+#             */
/*   Updated: 2017/08/07 11:26:00 by ybenoit          ###   ########.fr       */
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
		ft_putstr("error : number of ant incorrect -> ");
		return (NULL);
	}
	e->ant_n = ft_atoi(map_str[i++]);
	e = init_room(e, map_str + i);
	if (!e)
	{
		ft_putstr("error : declaration room failed -> ");
		return (NULL);
	}
	while (map_str[i] && !ft_strchr(map_str[i], '-'))
		i++;
	e->tab = init_tab(e, map_str);
	e->empty = (t_node*)malloc(sizeof(t_node));
	e->empty->name = -1;
	return (e);
}

int			check_exist_room(char *line, t_env *e, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		if (!ft_strcmp(ft_strsub(line, 0, ft_strlen_c(line, ' ')), e->all_r[i].name))
			return (0);
		i++;
	}
	return (1);
}

t_env			*init_room(t_env *e, char **map_str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	e->nb_room = count_room(map_str);
	e->all_r = (t_room*)malloc(sizeof(t_room) * e->nb_room);
	if (!e->all_r)
		return (NULL);
	while (map_str[i] && !ft_strchr(map_str[i], '-'))
	{
		if (!e)
			return (NULL);
		if (map_str[i][0] != '#')
		{
			if (!check_droom(map_str[i]))
				return (NULL);
			init_this_room(map_str[i], j, &e->all_r[j], e);
			j++;
		}
		else if (map_str[i][0] == '#' && map_str[i][1] == '#')
			e = check_sharp(e, map_str + i, j);
		i++;
	}
	return (e);
}
