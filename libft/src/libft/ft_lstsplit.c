/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:46:16 by rsathiad          #+#    #+#             */
/*   Updated: 2018/10/23 19:49:47 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstsplit(t_list *head, t_list **front, t_list **back)
{
	t_list *fast;
	t_list *slow;

	slow = head;
	fast = head->next;
	while (fast->next != NULL)
	{
		fast = fast->next;
		if (fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*back = slow->next;
	*front = head;
}
