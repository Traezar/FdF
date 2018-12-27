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

  if (dy < 0)
  {
    dy = -dy;
    stepy = -1;
  }
  else
    stepy = 1;
  if (dx < 0)
  {
    dx = -dx;
    stepx = -1;
  }
  else
    stepx = 1;
  dy = dy << 1;
  dx = dx << 1;
  if((0 <= x0) && (x0 < 1000) && (0 <= y0) && (y0 < 1000))
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
      if((0 <= x0) && (x0 < 1000) && (0 <= y0) && (y0 < 1000))
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
      if((0 <= x0) && (x0 < 1000) && (0 <= y0) && (y0 < 1000))
          mlx_pixel_put(gui.mlx, gui.win, x0, y0, 0xFFFFFF);
    }
  }
}

int xiso_convert(float x,float y,float z)
{
	int xcart;

	(void)y;
	xcart = round((x-z)*(cos(0.523599)));
	return (xcart+xorigin);
}

int yiso_convert(float x, float y, float z)
{
	int y_cart;

	y_cart = round((y + ((x+z)*(sin(0.523599)))));
	return (yorigin - y_cart);
}
