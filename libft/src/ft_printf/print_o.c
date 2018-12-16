/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:36:03 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 01:12:48 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		print_o(char chr, t_fmtblk blk, va_list ap)
{
	char		*tmp;
	uintmax_t	value;

	tmp = NULL;
	value = va_arg(ap, uintmax_t);
	if (blk.modifier == 1 && !(chr == 'O'))
		tmp = ft_uintmaxtoa_base((unsigned short)value, 8, 0);
	else if (blk.modifier == 2)
		tmp = ft_uintmaxtoa_base((unsigned char)value, 8, 0);
	else if ((blk.modifier == 4) || chr == 'O')
		tmp = ft_uintmaxtoa_base((unsigned long)value, 8, 1);
	else if (blk.modifier == 8)
		tmp = ft_uintmaxtoa_base((ULL)value, 8, 0);
	else if (blk.modifier == 16)
		tmp = ft_uintmaxtoa_base(value, 8, 0);
	else if (blk.modifier == 32)
		tmp = ft_uintmaxtoa_base((size_t)value, 8, 0);
	else if (blk.modifier == 0)
		tmp = ft_uintmaxtoa_base((unsigned int)value, 8, 0);
	return (pnf_o(blk, tmp, value));
}

int		print_per(t_fmtblk blk)
{
	char	padding;
	char	*tmp;
	char	*ret;
	int		value;

	ret = ft_strnew(1);
	ft_memset(ret, '%', 1);
	if (blk.flagstore & ZERO_P)
		padding = '0';
	else
		padding = ' ';
	tmp = addprecisiondioux(blk.precision, ret);
	ret = addwidth(blk.width, padding, blk.flagstore, tmp);
	value = ft_strlen(ret);
	write(1, ret, value);
	ft_strdel(&ret);
	return (value);
}

int		print_i(char chr, t_fmtblk blk, va_list ap)
{
	char		*tmp;
	intmax_t	value;

	tmp = NULL;
	value = va_arg(ap, intmax_t);
	if (blk.modifier == 0 && chr == 'i')
		tmp = ft_itoa(value);
	else if (blk.modifier == 1 && chr == 'i')
		tmp = ft_itoa((short)value);
	else if (blk.modifier == 2 && chr == 'i')
		tmp = ft_itoa((char)value);
	else if ((blk.modifier == 4 && chr == 'i'))
		tmp = ft_intmaxtoa_base((long)value, 10, 0);
	else if (blk.modifier == 8 && chr == 'i')
		tmp = ft_intmaxtoa_base((long long)value, 10, 0);
	else if (blk.modifier == 16 && chr == 'i')
		tmp = ft_intmaxtoa_base(value, 10, 0);
	else if (blk.modifier == 32 && chr == 'i')
		tmp = ft_intmaxtoa_base((size_t)value, 10, 0);
	return (pnf_d(blk, tmp, value));
}
