/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precisionandwidth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:52:42 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 01:33:49 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*applysharp(char *str, char c)
{
	char	*tmp;
	char	*ret;

	if (c == 'o' || c == 'O')
	{
		if (str[0] == '0')
			return (ft_strdup(str));
		tmp = ft_strnew(ft_strlen(str));
		ft_memset(tmp, '0', ft_strlen(str));
		ft_strcpy((tmp + 1), str);
		tmp[0] = '0';
	}
	else if (c == 'x' || c == 'X')
	{
		tmp = ft_strnew(ft_strlen(str) + 2);
		ft_memset(tmp, '0', ft_strlen(str) + 2);
		ft_strcpy((tmp + 2), str);
		tmp[1] = 'X';
		if (c == 'x')
			tmp[1] = 'x';
	}
	ret = ft_strdup(tmp);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (ret);
}

char	*addspace(int value, unsigned char flags, char *str)
{
	char *init;

	init = ft_strnew(ft_strlen(str) + 1);
	if ((flags & BLNK_P) && (value >= 0) && str[0] != ' ')
	{
		ft_memset(init, ' ', 1);
		ft_strcpy(init + 1, str);
	}
	else
		ft_strcpy(init, str);
	ft_strdel(&str);
	return (init);
}

char	*addsign(int value, unsigned char flags, char *str)
{
	char *init;

	init = ft_strnew(ft_strlen(str) + 1);
	if ((flags & SIGNED) && (value >= 0))
	{
		ft_memset(init, '+', 1);
		ft_strcpy(init + 1, str);
	}
	else
		ft_strcpy(init, str);
	ft_strdel(&str);
	return (init);
}

char	*checkneg(int value, char pad, int preci, char *str)
{
	char *ret;

	preci = 0;
	if (ft_strchr(str, ' ') == NULL)
		pad = '0';
	if ((value < 0) && pad == '0')
	{
		if (ft_strchr(str, '-') != NULL)
		{
			*ft_strchr(str, '-') = pad;
			str[0] = '-';
		}
	}
	else if ((value >= 0) && pad == '0')
	{
		if (ft_strchr(str, '+') != NULL)
		{
			*ft_strchr(str, '+') = pad;
			str[0] = '+';
		}
	}
	ret = ft_strdup(str);
	ft_strdel(&str);
	return (ret);
}
