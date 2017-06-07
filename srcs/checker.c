/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:14:40 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/07 16:15:42 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			check_nbant(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	if (ft_atoi(line) <= 0)
		return (0);
	return (1);
}

int			check_droom(char *line)
{
	int i;
	int ret;

	i = 1;
	ret = 0;
	if (line[1] && line[0] == '#' && line[1] == '#')
		return (1);
	while (line[i] && line[i - 1] != ' ')
		i++;
	while (line[i] && line[i] != ' ')
	{
		if (!ft_isdigit(line[i]))
			return (0);
		if (line[i + 1] && line[i + 1] == ' ')
			ret++;
		i++;
	}
	i++;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (ret == 1 ? 1 : 0);
}

int			check_liaison(char *str, t_env *e)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	i++;
	if (ret_nb_room(e, str) == -1 || ret_nb_room(e, str + i) == -1)
		return (0);
	else
		return (1);
}
