/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 11:40:12 by ybenoit           #+#    #+#             */
/*   Updated: 2017/08/07 11:30:55 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room			*init_this_room(char *str, int n_r, t_room *room, t_env *e)
{
	int		i;
	int		j;

	if (!room || !check_exist_room(str, e, n_r))
		exit(ft_printf("Error: duplicate room\n"));
	i = 0;
	room->n_r = n_r;
	while (str[i] && str[i] > 32)
		i++;
	room->name = (char*)malloc(sizeof(char) * (i + 2));
	if (!room->name)
		return (NULL);
	j = 0;
	while (j < i && str[j])
	{
		room->name[j] = str[j];
		j++;
	}
	room->name[j] = '\0';
	return (room);
}

t_env			*check_sharp(t_env *e, char **str, int n_r)
{
	int i;

	i = 0;
	if (!str[1])
		return (NULL);
	while (str[i] && str[i][0] == '#')
		i++;
	if (check_droom(str[i]))
	{
		if (!ft_strcmp("##end", str[0]))
			e->end = (e->end == -1) ? n_r : -2;
		else if (!ft_strcmp("##start", str[0]))
			e->start = (e->start == -1) ? n_r : -2;
		if (e->start == -2 || e->end == -2)
			return (NULL);
		return (e);
	}
	else
		return (NULL);
}
