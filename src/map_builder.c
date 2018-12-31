/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:12:03 by rsathiad          #+#    #+#             */
/*   Updated: 2018/12/25 15:12:05 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"

t_map *process_map_horizontal_lines(int fd, t_map *origin)
{
	char **coor;
  int row;
	int count;
  int column;
  t_map *map;
	char *line;

	line = ft_strnew(0);
	row = 0;
	column = 0;
	count = 0;
	map = NULL;
	while(get_next_line(fd, &line))
	{
    coor = ft_strsplit(line, ' ');
		while(coor[count] != NULL)
		{
			push_new_map(column ,row,ft_atoi(coor[count++]), &map);
			map->origin = origin;
			map->iso.x = xiso_convert(column, row, map->cart.z, map->origin);
			map->iso.y = yiso_convert(column, row, map->cart.z, map->origin);
			column += offset;
		}
		count = 0;
    row += offset;
		column = 0;
	}
	reverse_list(&map);
	return map;
}

t_map **process_map_vertical_lines(t_map *dot_map)
{
	int column;
	t_map **ret;

	column = get_columns(dot_map);
	ret = map_vertical(column, dot_map);
	return (ret);
}


void reverse_list(t_map **head_ref)
{
	t_map *previous;
	t_map *current;
	t_map *next;

	if (*head_ref == NULL)
		return;
	current = *head_ref;
	if (current->next == NULL)
		return;
	previous  = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head_ref = previous;
}

void push_new_map(int column, int row,int magnitude, t_map **map)
{
  t_map *new;

  new = malloc(sizeof(t_map));
  new->cart.x = column;
  new->cart.y = row;
  new->cart.z = magnitude * 10;
  new->next = *map;
	new->below = NULL;
  *map = new;
}
