/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 19:49:40 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/04 17:24:00 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ilen(int n, int base)
{
	int		len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

static int	conv_ex(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char		*ft_itoabase(int n, int base)
{
	char	*str;
	int		len;
	int		tmp;

	len = ilen(n, base);
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str[len--] = '\0';
	while (tmp /= base)
		str[len--] = conv_ex(tmp);
	if (n < 0)
		str[0] = '-';
	return (str);
}
