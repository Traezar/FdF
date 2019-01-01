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
#include <stdio.h>
#include "../minilibx_macos/mlx.h"

#define xorigin 500
#define yorigin 500
#define START_IMAGE  100
#define offset 50


 typedef struct s_point
 {
  float x;
  float y;
  float z;
 } t_point;

 typedef struct s_line
 {
   t_point start;
   t_point end;
 } t_line;

typedef struct s_iso
{
  float x;
  float y;
} t_iso;

typedef struct s_map
{
  t_point cart;
  t_iso iso;
  struct s_map *origin;
  struct s_map *next;
  struct s_map *below;

} t_map;

typedef struct s_gui
{
  void *mlx;
  void *win;
  struct s_map *origin;
} t_gui;


/*fdf.c*/
void lineate_horizontal(t_map *dot_map, t_gui gui);
void lineate_vertical(t_map **vertical, t_gui gui);
t_map *set_origin (void);
/*map_builder.c*/
t_map *process_map_horizontal_lines(int fd, t_map *origin);
t_map **process_map_vertical_lines(t_map *dot_map);
void reverse_list(t_map **head_ref);
void push_new_map(int column, int row,int magnitude, t_map **map);
int xiso_convert(float x,float  y,float z, t_map *origin);
int yiso_convert(float x,float  y,float z, t_map *origin);

/*line.c*/
void drawline_bresenham(t_map *start, t_map *end, t_gui gui);
void drawline (t_gui gui);

/*builder_util*/
t_map **map_vertical(int column,t_map *list);
void push_back_verticals(t_map *node, t_map **vertical);
int get_columns(t_map *dot_map);
int get_rows(t_map *dot_map);
t_map *map_duplicate(t_map *map);
