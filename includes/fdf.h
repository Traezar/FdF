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



 typedef struct s_point
 {
  float x;
  float y;
  float z;
 } t_point;

 typedef struct s_line
 {
   int stepx;
   int stepy;
   int dy;
   int dx;
   int fraction;
 } t_line;

typedef struct s_iso
{
  float x;
  float y;
} t_iso;

typedef struct s_map
{
  t_point *cart;
  t_iso *iso;
  struct s_map *next;
} t_map;

typedef struct s_fdf
{
  t_map *horizontal;
  t_map **vertical;
  void *mlx;
  void *win;
  int row;
  int column;
  int unit;
  struct s_map *origin;
} t_fdf;

/*fdf.c*/
void lineate_horizontal(t_map *horizontal, t_fdf *fdf);
void lineate_vertical(t_map **vertical, t_fdf *fdf);

/*map_builder.c*/
t_map *process_map_horizontal_lines(int fd, t_fdf *fdf);
t_map **process_map_vertical_lines(t_map *dot_map);
void reverse_list(t_map **head_ref);
void push_new_map(t_fdf *fdf, int magnitude, t_map **map);
int xiso_convert(float x,float  y,float z, t_map *origin);
int yiso_convert(float x,float  y,float z, t_map *origin);

/*line.c*/
void drawline_bresenham(t_map *start, t_map *end, t_fdf *fdf);

/*builder_util*/
t_map **map_vertical(int column,t_map *list);
void push_back_verticals(t_map *node, t_map **vertical);
int get_columns(t_map *dot_map);
int get_rows(t_map *dot_map);
t_map *map_duplicate(t_map *map);

/*hooks.c*/
int keyboard (int keycode, t_fdf *fdf);
void free_fdf(t_fdf **fdf);
void free_tmap(t_map **current);
void free_tmap_list(t_map **current);
/*hook_util.c*/
void get_rows_columns(char *file, t_fdf *fdf);
void set_origin (t_fdf *fdf);
void set_unit(t_fdf *fdf);
