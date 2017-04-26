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
	int				nb_room;
	int				start;
	int				end;
	int				**tab;
	char			***all_r;
}					t_env;

t_env				*fill_env(t_env *e, char **str);
t_env				*init_env(t_env *env);
t_env				*init_room(t_env *e, char **str);
char				**init_this_room(char *str, int n_r);
int					**init_tab(t_env *e, char **str);
int					**fill_tab(t_env *e, int **tab, char **str);
int					**init_this_liaison(t_env *e, int **tab, char *str);
t_env				*check_sharp(t_env *e, char **str, int n_r);
char				**save_file(char **ret);

#endif
