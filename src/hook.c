/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 22:20:09 by rsathiad          #+#    #+#             */
/*   Updated: 2019/01/03 15:37:08 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"

int	keyboard(int keycode, t_fdf *fdf)
{
	(void)fdf;
	if (keycode == 53)
		exit(0);
	return (0);
}

void free_fdf(t_fdf **chunk)
{
	t_fdf *fdf;
	t_map **ref;

	fdf = *chunk;
	free_tmap_list(&fdf->horizontal);
	ref = fdf->vertical;
	while(ref != NULL)
	{
		free_tmap_list(ref);
		ref++;
	}
	free(fdf->vertical);
	fdf->vertical = NULL;
	free(fdf->mlx);
	free(fdf->win);
	free_tmap(&fdf->origin);
	free(*chunk);
	chunk = NULL;
	return;
}

void free_tmap_list(t_map **list)
{
	t_map *current;
	t_map *previous;

	current = *list;
	while(current->next != NULL)
	{
		previous = current;
		current = current->next;
		free_tmap(&previous);
	}
	free_tmap(&current);
	*list = NULL;
	return;
}

void free_tmap(t_map **list)
{
	t_map *current;

	current = *list;
	free(current->iso);
	free(current->cart);
	free(current->next);
	free(current);
	*list = NULL;
	return ;
}
