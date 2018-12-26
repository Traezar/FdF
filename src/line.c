/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:34:36 by rsathiad          #+#    #+#             */
/*   Updated: 2018/12/23 12:34:40 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"



void drawline_previous_to_current(t_map *start, t_map *end, t_gui gui)
{
  double m;
  double x;
  double y;
  int increment;


  m = (end->iso.y - start->iso.y)/ (end->iso.x - start->iso.x);
  x = start->iso.x;

  increment = (end->iso.x > start->iso.x ? 1 : -1);
  while (x != end->iso.x )
  {
    y = round(m*x);
    mlx_pixel_put(gui.mlx, gui.win, x, y, 0xFFFFFF);
    x += increment;
  }
  return;
}
