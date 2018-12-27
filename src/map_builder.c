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

t_map *process_map(int fd)
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
		ft_printf("%s\n", line);
    coor = ft_strsplit(line, ' ');
		ft_printf("passed strsplit\n");
		while(coor[count] != NULL)
		{
			push_new_map(row ,column,ft_atoi(coor[count++]), &map);
			column += offset;
		}
		ft_printf("pushed first row\n");
		count = 0;
    row += offset;
		column = 0;
	}
	reverse_list(&map);
	return map;
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

void push_new_map(int row, int column,int magnitude, t_map **map)
{
  t_map *new;

  new = malloc(sizeof(t_map));
  new->cart.x = row;
  new->cart.y = column;
  new->cart.z = magnitude;
	new->iso.x = xiso_convert(row, column, magnitude);
	printf("The value of isox:%f\n", new->iso.x);
	new->iso.y = yiso_convert(row, column, magnitude);
	printf("The value of isoy:%f\n", new->iso.y);
  new->next = *map;
  *map = new;
}
