#include "../includes/lem_in.h"

char			**init_this_room(char *str, int n_r)
{
	int i;
	int j;
	char **room;

	room = (char**)malloc(sizeof(char*) * 2);
	if (!room)
		return (NULL);
	i = 0;
	room[0] = ft_itoabase(n_r, 10);;
	while (str[i] && str[i] > 32)
		i++;
	room[1] = (char*)malloc(sizeof(char) * (i + 2));
	j = 0;
	while (j < i && str[j])
	{
		room[1][j] = str[j];
		j++;
	}
	room[1][j] = '\0';
	return (room);
}

t_env			*check_sharp(t_env *e, char **str, int n_r)
{
	int i;

	i = 0;
	if (!str[1])
		return (NULL);
	while (str[i] && str[i][0] == '#' && str[i][1] == '#')
		i++;
	if (check_droom(str[i]))
	{
		if (ft_strstr("##end", str[0]))
			e->end = n_r;
		else if (ft_strstr("##start", str[0]))
			e->start = n_r;
		return (e);
	}
	else
		return (NULL);
}
