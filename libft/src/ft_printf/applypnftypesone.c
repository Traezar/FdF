/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applypnftypesone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:01:43 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 00:39:43 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		pnf_s(t_fmtblk blk, char *con)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int		value;

	if (con == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (blk.flagstore & ZERO_P)
		padding = '0';
	if (blk.flagstore & BLNK_P || blk.flagstore == '\0')
		padding = ' ';
	tmp = con;
	tmp = addprecisioncs(blk.precision, con);
	ret = addwidthcs(blk.width, blk.flagstore, tmp);
	value = ft_strlen(ret);
	write(1, ret, value);
	ft_strdel(&ret);
	return (value);
}

int		pnf_u(t_fmtblk blk, char *con)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int		value;

	ret = NULL;
	tmp = NULL;
	if (blk.flagstore & ZERO_P && blk.precision != '0')
		padding = '0';
	else
		padding = ' ';
	tmp = addprecisiondioux(blk.precision, con);
	ret = addwidth(blk.width, padding, blk.flagstore, tmp);
	value = ft_strlen(ret);
	write(1, ret, value);
	ft_strdel(&ret);
	return (value);
}

int		pnf_c(t_fmtblk blk, char con)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int		value;

	value = 0;
	if (con == 0)
	{
		padding = ' ';
		write(1, &padding, blk.width == 0 ? 0 : blk.width - 1);
		write(1, &value, 1);
		return (blk.width == 0 ? 1 : blk.width);
	}
	padding = ' ';
	tmp = ft_strnew(1);
	ft_memset(tmp, con, 1);
	ret = addwidth(blk.width, padding, blk.flagstore, tmp);
	value = ft_strlen(ret);
	write(1, ret, value);
	ft_strdel(&ret);
	return (value);
}

char	*addprecisioncs(int precision, char *str)
{
	char *ret;

	if (precision)
	{
		ret = ft_strnew(precision);
		ft_strncpy(ret, str, precision);
	}
	else
	{
		ret = ft_strnew(ft_strlen(str));
		ft_strncpy(ret, str, ft_strlen(str));
	}
	return (ret);
}

char	*addwidthcs(int width, unsigned char flags, char *str)
{
	char	*tmp1;
	char	*tmp2;
	int		len;

	len = ft_strlen(str);
	if (width <= 0 || width <= len)
	{
		tmp1 = ft_strdup(str);
		ft_strdel(&str);
		return (tmp1);
	}
	width = width - len;
	tmp1 = ft_strnew(width);
	tmp1 = ft_memset(tmp1, ' ', width);
	if (flags & RT_P)
		tmp2 = ft_strjoin(str, tmp1);
	else
		tmp2 = ft_strjoin(tmp1, str);
	ft_strdel(&str);
	str = ft_strdup(tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	return (str);
}
