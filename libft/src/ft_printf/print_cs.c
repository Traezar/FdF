/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 23:29:50 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 01:18:17 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		print_cs(char chr, t_fmtblk blk, va_list ap)
{
	char	*tmp;

	tmp = NULL;
	if (chr == 'c')
	{
		chr = va_arg(ap, int);
		return (pnf_c(blk, chr));
	}
	else
		tmp = (va_arg(ap, char *));
	if (blk.star != 0)
		return (0);
	return (pnf_s(blk, tmp));
}

int		print_wide(char chr, t_fmtblk blk, va_list ap)
{
	wchar_t wctmp;
	wchar_t *wstmp;

	wctmp = 0;
	wstmp = NULL;
	if ((blk.modifier == 4 && chr == 'c') || chr == 'C')
	{
		wctmp = va_arg(ap, wchar_t);
		return (pnf_wc(wctmp));
	}
	else
	{
		wstmp = va_arg(ap, wchar_t*);
		return (pnf_ws(wstmp));
	}
}

int		print_u(char chr, t_fmtblk blk, va_list ap)
{
	char		*tmp;
	uintmax_t	value;

	tmp = NULL;
	value = va_arg(ap, uintmax_t);
	if (blk.modifier == H && chr == 'u')
		tmp = ft_uintmaxtoa_base((unsigned short)value, 10, 1);
	else if (blk.modifier == HH && chr == 'u')
		tmp = ft_uintmaxtoa_base((unsigned char)value, 10, 1);
	else if ((blk.modifier == L) || (chr == 'U'))
		tmp = ft_uintmaxtoa_base(value, 10, 1);
	else if (blk.modifier == LL)
		tmp = ft_uintmaxtoa_base((unsigned long long)value, 10, 1);
	else if (blk.modifier == J)
		tmp = ft_uintmaxtoa_base(value, 10, 1);
	else if (blk.modifier == Z)
		tmp = ft_uintmaxtoa_base((size_t)value, 10, 1);
	else if (blk.modifier == 0)
		tmp = ft_uintmaxtoa_base((unsigned int)value, 10, 1);
	return (pnf_u(blk, tmp));
}
