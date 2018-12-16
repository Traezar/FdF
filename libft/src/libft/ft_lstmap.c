/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 17:24:35 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/19 21:53:20 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new_head;

	if (!lst || !f)
		return (NULL);
	if (!(new_head = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	tmp = new_head;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!tmp->next)
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new_head);
}
