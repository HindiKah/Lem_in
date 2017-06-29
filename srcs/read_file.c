/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:20:22 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/07 14:34:01 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		**save_file(char **ret)
{
	char	buff[2];
	int		s;
	int		g;

	g = 0;
	s = 0;
	ret = (char**)malloc(sizeof(char*) * 10000000);
	ret[s] = ft_strdup("");
	while ((g = read(0, buff, 1)) > 0)
	{
		buff[1] = '\0';
		if (s > 1000000)
			return (NULL);
		if (buff[0] == '\n')
		{
			s++;
			ret[s] = ft_strdup("");
		}
		else
			ret[s] = ft_strjoin_free(ret[s], ft_strdup(&buff[0]));
	}
	return (ret);
}
