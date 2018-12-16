/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 09:06:35 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/20 14:38:32 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	i = 0;
	if (!f || !s || !(p = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i] != '\0')
	{
		*(p + i) = (*f)(i, *(s + i));
		i++;
	}
	return (p);
}
