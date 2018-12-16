/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:43:23 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/18 12:01:33 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	i = ft_strlen(s1);
	ret = (char *)malloc(i + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		ret[i] = s1[i];
	ret[i] = '\0';
	return (ret);
}
