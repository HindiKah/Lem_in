#include "../includes/lem_in.h"

t_node			***give_way(t_node **tree, t_env *e)
{
	t_node ***ret;
	t_node **tmp;

	ret = (t_node***)malloc(sizeof(t_node**) * e->nb_room);
	while ((tmp = search_way(tree, e)))
		ret[i++] = tmp;
