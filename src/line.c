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

#define y0 (start->iso.y)
#define y1 (end->iso.y)
#define x0 (start->iso.x)
#define x1 (end->iso.x)

void drawline_bresenham(t_map *start, t_map *end, t_gui gui)
{
  int stepx;
  int stepy;
  int dy;
  int dx;
  int fraction;

  dx = x1 - x0;
  dy = y1 - y0;
  stepy = (dy < 0) ? -1 : 1;
  stepx = (dx < 0) ? -1 : 1;
  dy = (dy < 0) ? -dy : dy;
  dx = (dx < 0) ? -dx : dx;
  dy = dy << 1;
  dx = dx << 1;
  if((0 <= x0) && (x0 < 5000) && (0 <= y0) && (y0 < 5000))
      mlx_pixel_put(gui.mlx, gui.win, x0, y0, 0xFFFFFF);
  if (dx > dy)
  {
    fraction = dy - ( dx >> 1);
    while (x0 != x1)
    {
      x0 += stepx;
      if (fraction >= 0)
      {
        y0 += stepy;
        fraction -= dx;
      }
      fraction += dy;
      if((0 <= x0) && (x0 < 5000) && (0 <= y0) && (y0 < 5000))
          mlx_pixel_put(gui.mlx, gui.win, x0, y0, 0xFFFFFF);
    }
  }
  else
  {
    fraction = dx - (dy >> 1);
    while (y0 != y1)
    {
      if (fraction >= 0)
      {
        x0 += stepx;
        fraction -= dy;
      }
      y0 += stepy;
      fraction += dx;
      if((0 <= x0) && (x0 < 5000) && (0 <= y0) && (y0 < 5000))
          mlx_pixel_put(gui.mlx, gui.win, x0, y0, 0xFFFFFF);
    }
  }
}

int xiso_convert(float x,float y,float z, t_map *origin)
{
	int xcart;

  (void)z;
	xcart = (x + y) * cos(0.523599);
	return (xcart+ origin->iso.x);
}

int yiso_convert(float x, float y, float z, t_map *origin)
{
	int y_cart;

	y_cart = ((x - y) * sin(0.523599) + z);
	return (origin->iso.y - y_cart);
}
