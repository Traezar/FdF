/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:16:41 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/15 12:38:18 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char const *ret;

	if (s == NULL)
		return (NULL);
	while (*s == '\t' || *s == ' ' || *s == '\n')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	ret = s + ft_strlen(s) - 1;
	while (*ret == ' ' || *ret == '\n' || *ret == '\t')
		ret--;
	return (ft_strsub(s, 0, ret - s + 1));
}
