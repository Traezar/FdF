/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 02:07:42 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/17 19:21:39 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (*s2 == ' ' || *s1 == ' ')
		return ((char *)s1);
	if (ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	while (s1[i] && s2[j])
	{
		if (s1[i + j] == s2[j])
			j++;
		else
		{
			i++;
			j = 0;
		}
	}
	if (s2[j] == '\0')
		return ((char *)&s1[i]);
	return (NULL);
}
