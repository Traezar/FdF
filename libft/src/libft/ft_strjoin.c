/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:53:17 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/20 16:32:30 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *p;

	if (!s1 || !s2)
		return (NULL);
	if (!(p = (char *)(malloc(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(p, s1);
	ft_strcat(p, s2);
	return (p);
}
