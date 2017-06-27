/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_resize_nf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:30:20 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/19 17:30:21 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_resize_nf(char *str, int start, int end)
{
	char	*ret;
	int		i;

	if (end > (int)ft_strlen(str))
		return (str);
	i = 0;
	ret = (char*)malloc(sizeof(char) * (end - start + 1));
	while (start < end)
		ret[i++] = str[start++];
	ret[i] = '\0';
	return (ret);
}
