/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:10:36 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 00:00:44 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

unsigned char	ft_setbit(char name, int position)
{
	unsigned int	mask;
	int				ret;

	mask = 0;
	mask = 1 << position;
	ret = (mask | name);
	return (ret);
}
