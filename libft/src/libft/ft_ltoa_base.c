/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 00:30:27 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 00:31:45 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int		conv_ex(long nb, int is_cap)
{
	char c;

	c = 0;
	if (nb <= 0)
		nb = nb * -1;
	if (is_cap == 1)
		c = 'A';
	else
		c = 'a';
	if (nb >= 10)
		return (nb - 10 + c);
	else
		return (nb + '0');
}

char			*ft_ltoa_base(long num, unsigned int base, int is_cap)
{
	int			i;
	char		*str;
	long		tmp;

	i = (num > 0 ? -1 : (0));
	tmp = (num > 0 ? (-num) : num);
	while (tmp < 0)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = ft_strnew(++i)))
		return (NULL);
	str[i--] = '\0';
	num = -num;
	while (i >= 0)
	{
		tmp = num % base;
		str[i--] = conv_ex(tmp, is_cap);
		num /= base;
	}
	if (str[0] == '0' && ft_atoi(str) != 0)
		str[0] = '-';
	return (str);
}
