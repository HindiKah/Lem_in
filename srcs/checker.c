#include "../includes/lem_in.h"

int			check_nbant(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int			check_droom(char *line)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if (line[1] && line[0] == '#' && line [1] == '#')
		return (1);
	while (line[i] && line[i] != ' ')
		i++;
	i++;
	while (line[i] && line[i] != ' ')
	{
		if (!ft_isdigit(line[i]))
			return (0);
		if (line[i + 1] && line[i + 1] == ' ')
			ret++;
		i++;
	}
	i++;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (ret == 1 ? 1 : 0);
}

int			check_liaison(char *str, t_env *e)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	if (ret_nb_room(e, str) == -1 || ret_nb_room(e, str + i) == -1)
		return (0);
	else
		return (1);
}
