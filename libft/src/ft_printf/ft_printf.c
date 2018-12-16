/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:30:23 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 01:27:28 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdio.h>

int		outputstringmaker(char *strlst, va_list ap)
{
	t_fmtblk	head;

	head = formatblockmaker(strlst);
	return (functiondispatcher(head.conver, head, ap));
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*strtbprnt;
	int			len;

	strtbprnt = NULL;
	va_start(ap, format);
	len = workhorse(ap, format);
	va_end(ap);
	return (len);
}

int		workhorse(va_list ap, const char *format)
{
	char	*fmt;
	char	*tmp;
	int		i;
	int		writelen;

	i = 0;
	writelen = 0;
	fmt = (char*)&format[i];
	while (fmt[i] != '\0')
	{
		fmt = &fmt[i];
		i = 0;
		while (fmt[i] != '%' && fmt[i] != '\0')
			i++;
		write(1, fmt, i);
		writelen += i;
		if (fmt[i] == '\0')
			break ;
		tmp = conversionblockunpacker(&fmt[++i]);
		i += (ft_strlen(tmp));
		writelen += outputstringmaker(tmp, ap);
		ft_strdel(&tmp);
	}
	return (writelen);
}
