/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:56:07 by ybenoit           #+#    #+#             */
/*   Updated: 2017/09/15 11:02:24 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		error_code(t_env *e, char **ret, t_node **tree, int **ways)
{
	printf("Error\n");
	secure_free(&e, &ret, &tree, &ways);
	exit(0);
}
