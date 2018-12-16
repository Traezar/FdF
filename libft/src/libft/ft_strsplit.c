/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:11:37 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/20 15:32:37 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	word_count(char const *s, char c)
{
	int		newword;
	int		wordcount;
	size_t	i;

	i = 0;
	newword = 1;
	wordcount = 0;
	while (s[i])
	{
		if (newword && s[i] != c)
		{
			wordcount++;
			newword = 0;
		}
		if (s[i] == c)
			newword = 1;
		i++;
	}
	return (wordcount);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ap;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s || !(ap = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c))
				len++;
			ap[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	ap[j] = 0;
	return (ap);
}
