/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:03:10 by rsathiad          #+#    #+#             */
/*   Updated: 2018/08/21 19:50:10 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ilen(int n)
{
	int		len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		tmp;

	len = ilen(n);
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
	len--;
	str[len] = tmp % 10 + '0';
	while (tmp /= 10)
	{
		len--;
		str[len] = tmp % 10 + '0';
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
