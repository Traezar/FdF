/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:34:36 by rsathiad          #+#    #+#             */
/*   Updated: 2019/01/03 17:51:31 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"
#define Y0 (start->iso->y)
#define Y1 (end->iso->y)
#define X0 (start->iso->x)
#define X1 (end->iso->x)

static void		drawline_dx_greater(t_line *line,
		t_fdf *fdf, t_map **start, t_map **end)
{
	int	startx;
	int starty;
	int endx;
	int endy;

	startx = (*start)->iso->x;
	starty = (*start)->iso->y;
	endx = (*end)->iso->x;
	endy = (*end)->iso->y;
	line->fraction = line->dy - (line->dx >> 1);
	while (startx != endx)
	{
		startx += line->stepx;
		if (line->fraction >= 0)
		{
			starty += line->stepy;
			line->fraction -= line->dx;
		}
		line->fraction += line->dy;
		if ((0 <= startx) && (startx < 5000)
				&& (0 <= starty) && (starty < 5000))
			mlx_pixel_put(fdf->mlx, fdf->win, startx, starty, 0xFFFFFF);
	}
}

static void		drawline_dx_lesser(t_line *line,
		t_fdf *fdf, t_map **start, t_map **end)
{
	int startx;
	int starty;
	int endx;
	int endy;

	startx = (*start)->iso->x;
	starty = (*start)->iso->y;
	endx = (*end)->iso->x;
	endy = (*end)->iso->y;
	line->fraction = line->dx - (line->dy >> 1);
	while (starty != endy)
	{
		if (line->fraction >= 0)
		{
			startx += line->stepx;
			line->fraction -= line->dy;
		}
		starty += line->stepy;
		line->fraction += line->dx;
		if ((0 <= startx) && (startx < 5000)
				&& (0 <= starty) && (starty < 5000))
			mlx_pixel_put(fdf->mlx, fdf->win, startx, starty, 0xFFFFFF);
	}
}

void			drawline_bresenham(t_map *start, t_map *end, t_fdf *fdf)
{
	t_line		line;

	line.dx = X1 - X0;
	line.dy = Y1 - Y0;
	line.stepy = (line.dy < 0) ? -1 : 1;
	line.stepx = (line.dx < 0) ? -1 : 1;
	line.dy = (line.dy < 0) ? -line.dy : line.dy;
	line.dx = (line.dx < 0) ? -line.dx : line.dx;
	line.dy = line.dy << 1;
	line.dx = line.dx << 1;
	if ((0 <= X0) && (X0 < 5000) && (0 <= Y0) && (Y0 < 5000))
		mlx_pixel_put(fdf->mlx, fdf->win, X0, Y0, 0xFFFFFF);
	if (line.dx > line.dy)
		drawline_dx_greater(&line, fdf, &start, &end);
	else
		drawline_dx_lesser(&line, fdf, &start, &end);
}

int				xiso_convert(float x, float y, float z, t_map *origin)
{
	int		xcart;

	(void)z;
	xcart = (x + y) * cos(0.523599);
	return (xcart + origin->iso->x);
}

int				yiso_convert(float x, float y, float z, t_map *origin)
{
	int y_cart;

	y_cart = ((x - y) * sin(0.523599) + z);
	return (origin->iso->y - y_cart);
}
