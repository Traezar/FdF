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

t_map *process_map(int fd, char **lines)
{
	char **coor;
  int row;
  int column;
  t_map *map;

	row = 0;
	column = 0;
	while(get_next_line(fd, lines))
	{
    coor = ft_strsplit(*lines, ' ');
		while(coor[row++] != NULL)
      push_new_map(row,column,ft_atoi(coor[row]), &map);
    column++;
    row = 0;
	}
	return map;
}

void push_new_map(int row, int column,int magnitude, t_map **map)
{
  t_map *new;

  new = malloc(sizeof(t_map));
  new->cart.x = row;
  new->cart.y = column;
  new->cart.z = magnitude;
	new->iso.x = xiso_convert(row, column, magnitude);
	new->iso.y = yiso_convert(row, column, magnitude);
  new->next = *map;
  *map = new;
}

double xiso_convert(double x,double y,double z)
{
	double xcart;

	(void)y;
	xcart = (x-z)*(cos(0.46365));
	return (xcart+xorigin);
}

double yiso_convert(double x, double y, double z)
{
	double y_cart;

	y_cart = (y + ((x+z)*(sin(0.46365))));
	return (yorigin - y_cart);
}
