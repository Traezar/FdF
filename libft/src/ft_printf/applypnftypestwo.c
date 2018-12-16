/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applypnftypestwo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:59:06 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 13:59:38 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		pnf_o(t_fmtblk blk, char *con, uintmax_t value)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int		retn;

	if (value == 0 && blk.dot)
	{
		ft_strdel(&con);
		con = ft_strnew(0);
	}
	if (blk.flagstore & ZERO_P && blk.precision != '0')
		padding = '0';
	else
		padding = ' ';
	tmp = addprecisiondioux(blk.precision, con);
	ret = addsharp_o(blk, tmp);
	tmp = addwidth(blk.width, padding, blk.flagstore, ret);
	retn = ft_strlen(tmp);
	write(1, tmp, retn);
	ft_strdel(&tmp);
	return (retn);
}

int		pnf_x(t_fmtblk blk, char *con, uintmax_t value)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int		retn;

	ret = NULL;
	if (value == 0 && blk.dot)
	{
		ft_strdel(&con);
		con = ft_strnew(0);
	}
	tmp = addprecisiondioux(blk.precision, con);
	padding = ' ';
	if (blk.flagstore & ZERO_P && blk.precision != '0')
		padding = '0';
	ret = addsharp_x(blk, tmp, value);
	tmp = addwidth(blk.width, padding, blk.flagstore, ret);
	adjusthex(tmp, blk);
	retn = ft_strlen(tmp);
	write(1, tmp, retn);
	ft_strdel(&tmp);
	return (retn);
}

int		pnf_wc(wchar_t con)
{
	write(1, &con, 1);
	return (1);
}

int		pnf_ws(wchar_t *con)
{
	int		writelen;

	if (con == NULL)
		return (0);
	writelen = 0;
	while (*con != '\0')
		writelen += pnf_wc(*con++);
	return (writelen);
}

int		pnf_p(t_fmtblk blk, char *con, uintmax_t value)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int		retn;

	if (value == 0 && blk.dot)
	{
		ft_strdel(&con);
		con = ft_strnew(0);
	}
	tmp = addprecisiondioux(blk.precision, con);
	padding = ' ';
	if (blk.flagstore & ZERO_P && blk.precision != '0')
		padding = '0';
	ret = applysharp(tmp, 'x');
	tmp = addwidth(blk.width, padding, blk.flagstore, ret);
	adjusthex(tmp, blk);
	retn = ft_strlen(tmp);
	write(1, tmp, retn);
	ft_strdel(&tmp);
	return (retn);
}
