#include "../includes/lem_in.h"

t_room			*init_this_room(t_room *room, char *str, int n_r)
{
	int i;
	int j;

	i = 0;
	j = 0;
	room->r_n = n_r;
	while (str[i] && str[i] <= 32)
		i++;
	room->name = (char*)malloc(sizeof(char) * (i + 1));
	if (!room->name)
		return (NULL);
	while (j < i && str[i])
	{
		room->name[j] = str[i];
		i++;
		j++;
	}
	room->name[j] = '\0';
	return (room);
}

t_env			*check_sharp(t_env *e, char **str, int n_r)
{
	if (ft_strstr("##end", str[0]))
		e->end = n_r;
	else if (ft_strstr("##start", str[0]))
		e->start = n_r;
	return (e);
}
