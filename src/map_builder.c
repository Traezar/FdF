/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:12:03 by rsathiad          #+#    #+#             */
/*   Updated: 2019/01/03 15:36:12 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"

t_map	*process_map_horizontal_lines(int fd, t_fdf *fdf)
{
	char	**coor;
	t_map	*map;
	char	*line;


	fdf->row = 0;
	map = NULL;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		fdf->column = 0;
		coor = ft_strsplit(line, ' ');
		ft_strdel(&line);
		while (coor[fdf->column] != NULL)
		{
			push_new_map(fdf, ft_atoi(coor[fdf->column]), &map);
			map->iso->x = xiso_convert((fdf->column * fdf->unit),(fdf->row * fdf->unit), map->cart->z, fdf->origin);
			map->iso->y = yiso_convert((fdf->column * fdf->unit),(fdf->row * fdf->unit), map->cart->z, fdf->origin);
			(fdf->column)++;
		}
		ft_free_dblarray(coor);
		(fdf->row)++;
	}
	ft_strdel(&line);
	reverse_list(&map);
	return (map);
}

t_map	**process_map_vertical_lines(t_map *dot_map)
{
	int		column;
	t_map	**ret;

	column = get_columns(dot_map);
	ret = map_vertical(column, dot_map);
	return (ret);
}

void	reverse_list(t_map **head_ref)
{
	t_map *previous;
	t_map *current;
	t_map *next;

	if (*head_ref == NULL)
		return ;
	current = *head_ref;
	if (current->next == NULL)
		return ;
	previous = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head_ref = previous;
}

void	push_new_map(t_fdf *fdf, int magnitude, t_map **map)
{
	t_map *new;

	if (!(new = malloc(sizeof(t_map)))
			|| !(new->cart = malloc(sizeof(t_point)))
			|| !(new->iso = malloc(sizeof(t_iso))))
	{
		ft_printf("Error allocation memory\n");
		exit(0);
	}
	new->cart->x = fdf->column;
	new->cart->y = fdf->row;
	new->cart->z = magnitude * 3;
	new->next = *map;
	*map = new;
}
