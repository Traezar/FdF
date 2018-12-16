/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:11:43 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 14:13:40 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_fmtblk	formatblockmaker(char *str)
{
	t_fmtblk	store;

	store = formatinit(&store);
	store.flagstore = flaghandler(str);
	while (!(isflag(*str) == 1) && (*str != '\0') && (*str != '*'))
		str++;
	if (*str == '*')
		store.star = *str;
	if (ft_isdigit(*str))
		store.width = ft_atoi(str);
	while ((*str != '.') && (isconversionchr(*str) == 1) && (ismodi(*str) == 1)
			&& (*str != '\0'))
		str++;
	str = precisionndot(str, &store);
	if (isconversionchr(*str) == 1)
	{
		store.modifier = modihandler(&(*str));
		while (isconversionchr(*str) == 1 && *str != '\0')
			str++;
	}
	if (isconversionchr(*str) == 1)
		store.conver = '*';
	else
		store.conver = *str;
	return (store);
}

t_fmtblk	formatinit(t_fmtblk *store)
{
	store->dot = 0;
	store->width = 0;
	store->precision = 0;
	store->conver = 0;
	store->flagstore = 0;
	store->modifier = 0;
	store->star = 0;
	return (*store);
}

int			ismodi(char c)
{
	char *s;

	s = "hljtzq\0";
	while (*s != '\0')
	{
		if (*s++ == c)
			return (c);
	}
	return (1);
}

int			functiondispatcher(char chr, t_fmtblk head, va_list ap)
{
	int(*f)(char chr, t_fmtblk head, va_list ap);

	if (((head.modifier == 4 && chr == 'c') || (chr == 'C')) ||
			((head.modifier == 4 && chr == 's') || (chr == 'S')))
		(f) = &print_wide;
	else if (chr == 'o' || chr == 'O')
		(f) = &print_o;
	else if (chr == 'u' || chr == 'U')
		(f) = &print_u;
	else if ((chr == 'x') || (chr == 'p'))
		(f) = &print_x;
	else if (chr == 'X')
		(f) = &print_lx;
	else if (chr == 'c' || chr == 's')
		(f) = &print_cs;
	else if (chr == 'i')
		(f) = &print_i;
	else if (chr == '%')
		return (print_per(head));
	else if (chr == 'd' || chr == 'D')
		(f) = &print_d;
	else
		(f) = &print_g;
	return ((*f)(chr, head, ap));
}
