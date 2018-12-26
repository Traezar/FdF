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

int main (int ac, char **av)
{
	int fd;
	t_gui gui;
	char *map;
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
		dot_map = process_map(fd, &map);
		lineate(dot_map, gui);
		mlx_loop(gui.mlx);
	}
	return 0;
}


void lineate(t_map *dot_map, t_gui gui)
{
  t_map *current;
  t_map *previous;
	current = NULL;
	previous = NULL;

  while(dot_map!= NULL)
  {
		previous = current;
		current = dot_map;
		if(previous != NULL)
		drawline_previous_to_current(previous,current ,gui);
  }
}
