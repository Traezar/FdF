/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:22:54 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/06 13:50:11 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

unsigned char	ft_clearbit(char name, int position)
{
	unsigned int	mask;

	mask = 0;
	mask = 1 << position;
	return (name & ~mask);
}
