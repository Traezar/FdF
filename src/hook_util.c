/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 22:20:33 by rsathiad          #+#    #+#             */
/*   Updated: 2019/01/03 15:41:30 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"

void	get_rows_columns(char *file, t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	**array;

	fd = open(file, O_RDONLY);
	fdf->row = 1;
	fdf->column = 0;
	line = NULL;
	if (get_next_line(fd, &line))
	{
		array = ft_strsplit(line, ' ');
		while (array[fdf->column] != NULL)
			(fdf->column)++;
		ft_free_dblarray(array);
	}
	ft_strdel(&line);
	while (get_next_line(fd, &line))
	{
		ft_strdel(&line);
		(fdf->row)++;
	}
	ft_printf("The number of rows is : %i\n", fdf->row);
	ft_printf("The number of columns is : %i\n", fdf->column);
	ft_printf("The number of area is : %i\n", fdf->row * fdf->column);
	ft_strdel(&line);
	return ;
}

void	set_origin(t_fdf *fdf)
{
	t_map	*origin;
	int		w;
	int		h;

	w = 600;
	h = 600;
	origin = malloc(sizeof(t_map));
	origin->cart = malloc(sizeof(t_point));
	origin->iso = malloc(sizeof(t_iso));
	origin->cart->x = w;
	origin->cart->y = h;
	origin->iso->x = 0;
	origin->iso->y = 800;
	fdf->origin = origin;
	return ;
}

void	set_unit(t_fdf *fdf)
{
	int		column;
	int		row;
	int		area;

	column = fdf->column;
	row = fdf->row;
	area = row * column;
	if (area <= 50)
		fdf->unit = 50;
	else if (area <= 250)
		fdf->unit = 40;
	else if (area <= 2500)
		fdf->unit = 10;
	else if (area <= 10000)
		fdf->unit = 8;
	else
		fdf->unit = 3;
	return ;
}
