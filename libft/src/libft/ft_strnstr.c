/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 03:46:28 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/18 09:36:23 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if ((s1[i] == '\0') || (ft_strlen(s1) < ft_strlen(s2)))
		return (NULL);
	if (s2[i] == '\0')
		return ((char *)&s1[i]);
	while (s1[i] && s2[j] && (i + j < len))
	{
		if (s1[i + j] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		else
		{
			i++;
			j = 0;
		}
	}
	return (NULL);
}
