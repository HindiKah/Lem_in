/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:58:01 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/19 19:10:42 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_env			*init_env(t_env *e)
{
	char line;

	init_ant_n(e, line);
	if (ft_strstr(line, "##"))
	{
		if (ft_strstr(line, "start"))
			init_start(e, line);
		else if (ft_strstr(line, "line"))
			init_end(e, line);
	}
	else
		if (!ft_strchr(line, '-'))
			init_room(e, line);
		else
		{
			init_tab(e->tab);
			init_liaison(e, line);
		}
	return (e);
}
