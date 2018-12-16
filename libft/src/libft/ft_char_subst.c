/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_subst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:15:22 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/08 20:36:46 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_char_subst(char pattern, char *sub, char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	j = 0;
	ret = ft_strnew(ft_strlen(str) + (ft_count_char(pattern, str)
				* ft_strlen(str)) + 1);
	while (str[++i] != '\0')
	{
		while (str[i] != pattern && str[i] != '\0')
		{
			ret[j] = str[i];
			i++;
			j++;
		}
		if (str[i] == '\0')
			break ;
		ft_strcpy(ret + j, sub);
		j += ft_strlen(sub);
	}
	ret[j] = '\0';
	return (ret);
}
