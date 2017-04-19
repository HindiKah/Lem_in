/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:41:00 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/19 19:01:08 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libftprintf_42/includes/ft_printf.h"
# include "../libftprintf_42/includes/libft.h"

typedef struct		s_env
{
	int				ant_n;
	int				start;
	int				end;
	unsigned int	**tab;
	char			**room_name;
}					t_env;

t_env				*init_env(t_env *env);

#endif
