/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:51:06 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/08 19:47:56 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#define WHITESPACE(x) x == '\t' || x == '\n' || x == ' '

int		ft_wordsize(char *str)
{
	int		i;

	i = 0;
	while (WHITESPACE(*str) && (*str != '\0'))
		str++;
	while (WHITESPACE(str[i]) && (str[i] != '\0'))
		i++;
	return (i);
}

int		ft_word_count(char *str)
{
	int word_count;
	int i;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		while (WHITESPACE(str[i]) && str[i] != '\0')
			i++;
		while (!(WHITESPACE(str[i])) && str[i] != '\0')
			i++;
		while (WHITESPACE(str[i]) && str[i] != '\0')
			i++;
		word_count++;
	}
	return (word_count);
}

char	**ft_split_whitespace(char *str)
{
	int		word_count;
	int		words_entered;
	char	**words;
	char	*word;
	int		i;

	i = 0;
	words_entered = 0;
	word_count = ft_word_count(str);
	words = (char**)malloc(sizeof(char*) * (word_count + 1));
	while (words_entered < word_count)
	{
		word = (char*)malloc(sizeof(char) * (ft_wordsize(str) + 1));
		while (WHITESPACE(str[0]) && str[0] != '\0')
			str++;
		while (!(WHITESPACE(str[0])) && str[0] != '\0')
			word[i++] = *str++;
		word[i] = '\0';
		words[words_entered++] = word;
		i = 0;
	}
	words[words_entered] = NULL;
	return (words);
}
