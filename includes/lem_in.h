/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:41:00 by ybenoit           #+#    #+#             */
/*   Updated: 2017/08/07 11:42:51 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/includes/libft.h"
# define USAGE "usage: [-m[x]ipd] multi/info/print_ways(s)/display_map\n"
# define AUSAGE "1234567890pdmi"

typedef struct		s_node
{
	int				name;
	int				passed;
	int				ant_name;
	int				nb_ant;
	struct s_node	**next;
}					t_node;

typedef struct		s_room
{
	int				n_r;
	char			*name;
}					t_room;

typedef struct		s_env
{
	int				ant_n;
	int				way_start;
	int				current_way;
	int				way;
	int				nb_room;
	int				start;
	int				end;
	int				multi;
	int				force_way_use;
	int				nb_way_to_use;
	int				*pass;
	t_node			*empty;
	int				**tab;
	t_room			*all_r;
	int				d_m;
	int				p_w;
	int				nb_iter;
	int				error_code;
}					t_env;

typedef struct		s_ant
{
	int				name;
	int				pos;
}					t_ant;

int					check_exist_room(char *str, t_env *e, int j);
t_env				*fill_env(t_env *e, char **str);
t_env				*init_env(t_env *env);
t_env				*init_room(t_env *e, char **str);
t_room				*init_this_room(char *str, int n_r, t_room *r, t_env *e);
int					**init_tab(t_env *e, char **str);
int					**fill_tab(t_env *e, int **tab, char **str);
int					**init_this_liaison(t_env *e, int **tab, char *str);
int					ret_nb_room(t_env *e, char *str);
t_env				*check_sharp(t_env *e, char **str, int n_r);
char				**save_file(char **ret);
t_node				*give_next_node(t_env *e, t_node *prev, int node);
t_node				**map_tree_init(t_env *e);
int					is_it_passed(int *pass, int node);
int					count_neighbour(t_env *e, int node);
int					*add_tab_value(int *tab, int n);
t_node				*init_node(t_node *node, t_env *e, int n);
t_node				*link_node(t_node *node, t_env *e, t_node **tree);
t_node				*search_node(t_node **node, t_env *e, int n);
int					*search_way(t_node **tree, t_node **start, t_env *e,
					int **ret);
int					*add_end_tab(int *ret, int n, int end, t_env *e);
int					**give_way(t_node **tree, t_env *e);
int					give_last_tab(int *tab);
int					way_len(int *tab);
void				sort_tab(int **tab);
void				switch_tab(int **tab, int a, int b);
void				del_link(t_node **tree, int *tab, t_env *e);
void				del_useless(int **tab);
void				move_ant(t_env *e, int **ways, t_node **tree);
void				move_next(int *way, t_env *e, t_node **tree, int way_n);
void				init_tree_ants(t_env *e, t_node **tree);
int					check_nbant(char *line);
int					check_droom(char *line);
int					check_liaison(char *str, t_env *e);
int					find_optiway(t_env *e, int **ways);
int					analyse_ac(t_env *e, char *str);
void				print_pass(int *tab);
void				display_link(t_node **tree, t_env *e);
void				display_map(t_env *e);
void				print_tab(int *tab, t_env *e);
void				print_passed(t_node **tree, t_env *e);
void				print_way(int **tab, t_env *e);
void				error_code(t_env *e, char **ret, t_node **tree, int **ways);
#endif
