/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:32:16 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 01:25:39 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*conversionblockunpacker(const char *format)
{
	int		len;
	char	*ret;

	ret = NULL;
	len = 0;
	while (isconversionchr(format[len]) == 1)
		len++;
	ret = ft_strsub(format, 0, len + 1);
	return (ret);
}

char	isflag(char c)
{
	char *s;

	s = "0+ -#\0";
	while (*s != '\0')
	{
		if (*s++ == c)
			return (c);
	}
	return (1);
}

int		isconversionchr(char c)
{
	char *s;

	s = "sSpdDioOuUxXcC%\0";
	while (*s != '\0')
	{
		if (*s++ == c)
			return (c);
	}
	return (1);
}

char	flaghandler(char *str)
{
	unsigned char	store;

	store = 0;
	while (isconversionchr(*str) == 1 && !(ft_isdigit(*str) && *str != '0')
	&& *str != '.')
	{
		if (*str == '0')
			store = ft_setbit(store, 4);
		if (*str == '#')
			store = ft_setbit(store, 0);
		else if (*str == '+')
			store = ft_setbit(store, 1);
		else if (*str == ' ')
			store = ft_setbit(store, 2);
		else if (*str == '-')
			store = ft_setbit(store, 3);
		str++;
	}
	if (isconversionchr(*str) == 'O' || isconversionchr(*str) == 'X')
		store = ft_setbit(store, 5);
	if ((store & BLNK_P) && (store & SIGNED))
		store = ft_clearbit(store, 2);
	if ((store & ZERO_P) && (store & RT_P))
		store = ft_clearbit(store, 4);
	return (store);
}

int		modihandler(char *str)
{
	int				i;
	unsigned char	store;

	i = 0;
	store = 0;
	if (str[i] == 'h' && str[i + 1] != 'h')
		return (1);
	else if (str[i] == 'h' && str[i + 1] == 'h')
		return (2);
	else if (str[i] == 'l' && str[i + 1] != 'l')
		return (4);
	else if (str[i] == 'l' && str[i + 1] == 'l')
		return (8);
	else if (str[i] == 'j')
		return (16);
	else if (str[i] == 'z')
		return (32);
	else
		return (0);
}
