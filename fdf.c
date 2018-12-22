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

#include "includes/fdf.h"
#include "minilibx/mlx.h"


int main (void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr != NULL)
	{
		win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");
		mlx_pixel_put(mlx_ptr, win_ptr, 250, 250 , 0xFF0000);
		mlx_loop(mlx_ptr);
	}
	return 0;
}
