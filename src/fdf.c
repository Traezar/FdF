/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 03:23:17 by rsathiad          #+#    #+#             */
/*   Updated: 2019/01/03 15:47:48 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int		main(int ac, char **av)
{
	int		fd;
	t_fdf	*fdf;

	if (ac != 2)
		exit(0);
	fdf = malloc(sizeof(t_fdf));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_printf("Error opening the file provided");
	else
	{
		fdf->mlx = mlx_init();
		get_rows_columns(av[1], fdf);
		set_unit(fdf);
		fdf->win = mlx_new_window(fdf->mlx, 5000, 5000, "FDF");
		set_origin(fdf);
		fdf->horizontal = process_map_horizontal_lines(fd, fdf);
		fdf->vertical = process_map_vertical_lines(fdf->horizontal);
		lineate_horizontal(fdf->horizontal, fdf);
		lineate_vertical(fdf->vertical, fdf);
		mlx_key_hook(fdf->win, keyboard, fdf);
		mlx_loop(fdf->mlx);
		free_fdf(&fdf);
	}
	return (0);
}

void	lineate_horizontal(t_map *horizontal, t_fdf *fdf)
{
	t_map	*hcurrent;
	t_map	*hprevious;

	hcurrent = horizontal;
	hprevious = NULL;
	while (horizontal != NULL)
	{
		hprevious = hcurrent;
		hcurrent = horizontal;
		if (hcurrent->cart->y == hprevious->cart->y)
			drawline_bresenham(hprevious, hcurrent, fdf);
		horizontal = horizontal->next;
	}
	return ;
}

void	lineate_vertical(t_map **vertical, t_fdf *fdf)
{
	t_map *vcurrent;
	t_map *vprevious;

	vcurrent = NULL;
	vprevious = NULL;
	while (*vertical != NULL)
	{
		vcurrent = *vertical;
		vprevious = NULL;
		while (vcurrent->next != NULL && *vertical != NULL)
		{
			vprevious = vcurrent;
			vcurrent = vcurrent->next;
			drawline_bresenham(vprevious, vcurrent, fdf);
		}
		vertical++;
	}
	return ;
}
