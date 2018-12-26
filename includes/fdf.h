/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:16:03 by rsathiad          #+#    #+#             */
/*   Updated: 2018/12/20 22:17:51 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <math.h>
#include <fcntl.h>
#include "../minilibx_macos/mlx.h"

#define xorigin 100
#define yorigin 100
#define START_IMAGE  100
typedef struct s_gui
{
  void *mlx;
  void *win;
} t_gui;

 typedef struct s_point
 {
  double x;
  double y;
  double z;
 } t_point;

 typedef struct s_line
 {
   t_point start;
   t_point end;
 } t_line;

typedef struct s_iso
{
  double x;
  double y;
} t_iso;

typedef struct s_map
{
  t_point cart;
  t_iso iso;
  struct s_map *next;
} t_map;

/*fdf.c*/
void lineate(t_map *dot_map, t_gui gui);
/*map_builder.c*/
t_map *process_map(int fd, char **map);
void push_new_map(int row, int column,int magnitude, t_map **map);
double xiso_convert(double x,double  y,double z);
double yiso_convert(double x,double  y,double z);

/*line.c*/
void drawline_previous_to_current(t_map *start, t_map *end, t_gui gui);
