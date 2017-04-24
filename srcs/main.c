/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:31:44 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/19 18:57:54 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
void		display_map(t_env *e);

int			main(int argc, char **argv)
{
	t_env	*e;
	char	**ret;

	e = fill_env(e, save_file(ret));
	display_map(e);
	return (0);
}

void		display_map(t_env *e)
{
	ft_printf("\t\tMAP\n");
	ft_printf("ant_n -> %d\nnb_room -> %d\nstart -> room n'%d'\nend -> room n'%d'\n\n", e->ant_n, e->nb_room, e->start, e->end);
}

