/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 11:40:12 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/27 11:41:02 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room			*init_this_room(char *str, int n_r, t_room *room)
{
	int		i;
	int		j;

	if (!room)
		return (NULL);
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
		if (ft_strstr("##end", str[0]))
			e->end = n_r;
		else if (ft_strstr("##start", str[0]))
			e->start = n_r;
		return (e);
	}
	else
		return (NULL);
}
