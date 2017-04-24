#include "../includes/lem_in.h"

char		**save_file(char **ret)
{
	char	buff[2];
	int		secure;
	int		g;

	g = 0;
	secure = 0;
	ret = (char**)malloc(sizeof(char*) * 1000);
	ret[secure] = ft_strdup("");
	while ((g = read(0, buff, 1)) > 0)
	{
		if (g <= 0)
		{
			ret[secure] = NULL;
			return (ret);
		}
		buff[1] = '\0';
		if (secure > 999)
			return (NULL);
		if (buff[0] == '\n')
		{
			secure++;
			ret[secure] = ft_strdup("");
		}
		else
			ret[secure] = ft_strjoin_free(ret[secure],ft_strdup(&buff[0]));
	}
	return (ret);
}
