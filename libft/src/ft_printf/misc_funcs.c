/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 13:37:36 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 14:12:08 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*addsharp_x(t_fmtblk blk, char *tmp, uintmax_t value)
{
	char *ret;

	if (blk.flagstore & SH_ON && (value != 0))
		ret = applysharp(tmp, blk.flagstore & O_X ? 'X' : 'x');
	else
	{
		ret = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	return (ret);
}

char	*addsharp_o(t_fmtblk blk, char *tmp)
{
	char *ret;

	if (blk.flagstore & SH_ON)
		ret = applysharp(tmp, blk.flagstore & O_X ? 'O' : 'o');
	else
	{
		ret = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	return (ret);
}

char	*adjusthex(char *tmp, t_fmtblk blk)
{
	if ((blk.flagstore & SH_ON) && ft_strchr(tmp, 'x') != (tmp + 1)
			&& (blk.flagstore & ZERO_P))
	{
		*ft_strchr(tmp, 'x') = '0';
		*(tmp + 1) = 'x';
	}
	return (tmp);
}

char	*precisionndot(char *str, t_fmtblk *store)
{
	if (*str == '.')
	{
		store->dot = 1;
		store->precision = ft_atoi(++str);
		while (ft_isdigit(*str))
			str++;
	}
	return (str);
}
