/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:41:00 by ybenoit           #+#    #+#             */
/*   Updated: 2017/05/04 16:39:27 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libftprintf_42/includes/ft_printf.h"
# include "../libftprintf_42/includes/libft.h"

typedef struct		s_node
{
	char			from;
	int				name;
	int				ant;
	int				depth;
	struct s_node	*previous;
	struct s_node	**next;
}					t_node;

typedef struct		s_way
{
	char			*way;
	int				len;
}					t_way;

typedef struct		s_env
{
	int				ant_n;
	int				way;
	int				nb_room;
	int				start;
	int				end;
	int				*pass;
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
t_node				*give_next_node(t_env *e, t_node *prev, int node);
t_node				*map_tree_init(t_env *e);
int					is_it_passed(int *pass, int node);
int					count_neighbour(t_env *e, int node);
int					*add_tab_value(int *tab, int n);

void				print_pass(int *tab);
#endif
