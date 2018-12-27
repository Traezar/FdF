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
	origin->cart.x = 500;
	origin->cart.y = 500;
	origin->iso.x = xiso_convert(500, 500, 1);
	origin->iso.y = xiso_convert(500, 500, 1);
	return (origin);
}
int main (int ac, char **av)
{
	int fd;
	t_gui gui;
	t_map *dot_map;

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
			gui.win = mlx_new_window(gui.mlx, 1000, 1000, "FDF");
		gui.origin = set_origin();
		dot_map = process_map(fd);
		ft_printf("dot_map created\n");
		lineate(dot_map, gui);
		mlx_loop(gui.mlx);
	}
	return 0;
}



void lineate(t_map *dot_map, t_gui gui)
{
  t_map *current;
  t_map *previous;

	current = gui.origin;
	previous = NULL;
	ft_printf("Entered lineate\n");
  while(dot_map!= NULL)
  {
		previous = current;
		current = dot_map;
		drawline_bresenham(previous,current ,gui);
		dot_map = dot_map->next;
  }
	return;
}
