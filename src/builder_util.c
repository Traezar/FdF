/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 12:09:59 by rsathiad          #+#    #+#             */
/*   Updated: 2018/12/28 12:10:02 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"

t_map **map_vertical(int column,t_map *list)
{
  int ccount;
  int rcount;
  t_map **map;

  rcount = 0;
  map = malloc((sizeof(t_map*)) * column);
  while (list != NULL)
  {
    ccount = 0;
    while (ccount < column && list != NULL)
    {
      if (rcount == 0)
      map[ccount] = NULL;
      push_back_verticals(map_duplicate(list), (map + ccount));
      list = list->next;
      ccount++;
      ft_printf("The count is %i\n", ccount);
    }
    rcount++;
  }
  map[column]= NULL;
  return map;
}

int get_columns(t_map *dot_map)
{
  int column;
  t_map *ptr;

  column = 0;
  ptr = dot_map;
  while (ptr != NULL && (ptr->cart.y == dot_map->cart.y))
  {
    ptr = ptr->next;
    column++;
  }
  return (column);
}

int get_rows(t_map *dot_map)
{
  int row;
  t_map *fast;
  t_map *slow;

  fast = dot_map;
  slow = dot_map;
  row = 0;
  while (fast != NULL )
  {
    if (fast->cart.y != slow->cart.y)
     row++;
    fast = fast->next;
    slow = slow->next;
  }
  return (row);
}

t_map *map_duplicate(t_map *map)
{
  t_map *new;

  new = malloc(sizeof(t_map));
  new->cart.x = map->cart.x;
  new->cart.y = map->cart.y;
  new->cart.z = map->cart.z;
  new->iso.x = map->iso.x;
  new->iso.y = map->iso.y;
  new->origin= map->origin;
  new->next = NULL;
  new->below = NULL;
  return (new);
}

void push_back_verticals(t_map *node, t_map **vertical)
{
  t_map *list;

  list = NULL;
  node->next = NULL;
  if (*vertical == NULL)
    *vertical = node;
  else
  {
    list = *vertical;
    while(list->next != NULL)
    list = list->next;
    list->next = node;
  }
  return;
}
