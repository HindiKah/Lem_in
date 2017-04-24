#include "../includes/lem_in.h"

int				**init_tab(t_env *e, char **str)
{
	int **ret;
	int i;
	int j;

	j = 0;
	i = 0;
	ret = (int**)malloc(sizeof(int*) * e->nb_room);
	if (!ret)
		return (NULL);
	while (i < e->nb_room)
	{
		ret[i] = (int*)malloc(sizeof(int) * e->nb_room);
		if (!ret[i])
			return (NULL);
		while (j < e->nb_room)
			ret[i][j++] = 0;
		i++;
	}
	ret = fill_tab(e, ret, str);
	return (ret);
}

int					**fill_tab(t_env *e, int **tab, char **str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i][0] != '#')
			init_this_liaison(e, tab, str[i]);
		i++;
	}
	return (tab);
}

int					ret_nb_room(t_env *e, char *str)
{
	int i;
	int j;

	i = 0;
	while (j < e->nb_room)
	{
		j = 0;
		while (str[i] && str[i] == e->all_r[j].name[i])
			i++;
		if (str[i] == '-' || str[i] == '\0')
			return (e->all_r[j].r_n);
		j++;
	}
	return (-1);
}

int					**init_this_liaison(t_env *e, int **tab, char *str)
{
	int i;

	i = 0;
	while (str[i] != '-')
		i++;
	tab[ret_nb_room(e, str)][ret_nb_room(e, str + i)] = 1;
	tab[ret_nb_room(e, str + i)][ret_nb_room(e, str)] = 1;
	return (tab);
}
