/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmergesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:42:59 by rsathiad          #+#    #+#             */
/*   Updated: 2018/10/22 13:41:49 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*sortedmerge(t_list *front, t_list *back)
{
	t_list *result;

	result = NULL;
	if (front == NULL)
		return (back);
	if (back == NULL)
		return (front);
	if (ft_strcmp(front->content, back->content) <= 0)
	{
		result = front;
		result->next = sortedmerge(front->next, back);
	}
	else
	{
		result = back;
		result->next = sortedmerge(back->next, front);
	}
	return (result);
}

void	ft_lstmergesort(t_list **head)
{
	t_list *front;
	t_list *back;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	else
	{
		ft_lstsplit(*head, &front, &back);
		ft_lstmergesort(&front);
		ft_lstmergesort(&back);
		*head = sortedmerge(front, back);
		return ;
	}
}
