/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:12:14 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/06 15:46:50 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_subnjoin(char *s1, char *s2, int start, int end)
{
	char *tmpone;
	char *tmptwo;

	if (!s1 || !s2)
		return (NULL);
	tmpone = ft_strsub(s2, start, end);
	tmptwo = ft_strjoin(s1, tmpone);
	s1 = tmptwo;
	free(tmpone);
	return (s1);
}
