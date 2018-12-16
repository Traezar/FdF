/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:27:34 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 01:15:38 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		print_d(char chr, t_fmtblk blk, va_list ap)
{
	char		*tmp;
	intmax_t	value;

	tmp = NULL;
	value = va_arg(ap, intmax_t);
	if (blk.modifier == 0 && chr == 'd')
		tmp = ft_itoa(value);
	else if (blk.modifier == 1 && chr == 'd')
		tmp = ft_itoa((short)value);
	else if (blk.modifier == 2 && chr == 'd')
		tmp = ft_itoa((char)value);
	else if ((blk.modifier == 4 && chr == 'd') || (chr == 'D'))
		tmp = ft_intmaxtoa_base((long)value, 10, 0);
	else if (blk.modifier == 8 && chr == 'd')
		tmp = ft_intmaxtoa_base((long long)value, 10, 0);
	else if (blk.modifier == 16 && chr == 'd')
		tmp = ft_intmaxtoa_base(value, 10, 0);
	else if (blk.modifier == 32 && chr == 'd')
		tmp = ft_intmaxtoa_base(value, 10, 0);
	return (pnf_d(blk, tmp, value));
}

int		pnf_d(t_fmtblk blk, char *con, intmax_t value)
{
	char	padding;
	char	*tmp;
	char	*ret;

	if (value == 0 && blk.dot)
	{
		ft_strdel(&con);
		con = ft_strnew(0);
	}
	if (blk.flagstore & ZERO_P && blk.precision != '0')
		padding = '0';
	else
		padding = ' ';
	ret = addprecisiondioux(blk.precision, con);
	tmp = addsign(value, blk.flagstore, ret);
	if (blk.width > blk.precision && blk.precision && blk.width)
		padding = ' ';
	ret = addwidth(blk.width, padding, blk.flagstore, tmp);
	tmp = addspace(value, blk.flagstore, ret);
	ret = checkneg(value, padding, blk.precision, tmp);
	value = ft_strlen(ret);
	write(1, ret, value);
	ft_strdel(&ret);
	return (value);
}

char	*addprecisiondioux(int precision, char *str)
{
	int		len;
	char	*init;

	len = ft_strlen(str);
	if (str[0] == '-')
		len--;
	if (precision <= 0 || precision <= len)
	{
		init = ft_strdup(str);
		ft_strdel(&str);
		return (init);
	}
	init = ft_strnew(precision + len);
	precision = precision - len;
	ft_memset(init, '0', precision);
	ft_strcpy(init + precision, str);
	ft_strdel(&str);
	return (init);
}

char	*addwidth(int width, char pad, unsigned char flags, char *str)
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
	tmp1 = ft_strnew(width + 1);
	tmp1 = ft_memset(tmp1, pad, width);
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
