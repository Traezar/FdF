/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 03:23:17 by rsathiad          #+#    #+#             */
/*   Updated: 2018/12/16 03:24:03 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

t_map *set_origin (void)
{
	t_map *origin;

	origin = malloc(sizeof(t_map));
	origin->cart.x = 900;
	origin->cart.y = 900;
	origin->iso.x = 900;
	origin->iso.y = 900;
	return (origin);
}

int main (int ac, char **av)
{
	int fd;
	t_gui gui;
	t_map *horizontal;
	t_map **vertical;

	if(ac != 2)
		exit(0);
	gui.win = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_printf("Error opening the file provided");
	else
	{
		gui.mlx = mlx_init();
		if (gui.mlx != NULL)
			gui.win = mlx_new_window(gui.mlx, 5000, 5000, "FDF");
		gui.origin = set_origin();
		horizontal = process_map_horizontal_lines(fd, gui.origin);
		vertical = process_map_vertical_lines(horizontal);
		lineate_horizontal(horizontal, gui);
		lineate_vertical(vertical, gui);
		mlx_loop(gui.mlx);
	}
	return 0;
}

void lineate_horizontal(t_map *horizontal, t_gui gui)
{
  t_map *hcurrent;
  t_map *hprevious;

	hcurrent = gui.origin;
	hprevious = NULL;
  while(horizontal!= NULL)
  {
		hprevious = hcurrent;
		hcurrent = horizontal;
		if(hcurrent->cart.y == hprevious->cart.y)
		drawline_bresenham(hprevious,hcurrent ,gui);
		horizontal = horizontal->next;
  }
	return;
}

void lineate_vertical(t_map **vertical, t_gui gui)
{
	t_map *vcurrent;
  t_map *vprevious;

	vcurrent = NULL;
	vprevious = NULL;
	while(*vertical != NULL)
	{
		vcurrent = *vertical;
		vprevious = NULL;
		while(vcurrent->next != NULL && *vertical != NULL)
		{
			vprevious = vcurrent;
			vcurrent = vcurrent->next;
			drawline_bresenham(vprevious,vcurrent ,gui);
		}
		vertical++;
	}
	return;
}
