/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:46:45 by jlaurent          #+#    #+#             */
/*   Updated: 2023/01/19 16:46:45 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//LIB//
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#include "../mlx_linux/mlx.h"

//LIBFT//
# include "../libft/libft.h"


//DEFINE//

# define HAUTEUR	1920
# define LARGEUR	1080
# define FORWARD	13
# define BACK		1
# define LEFT		0
# define RIGHT		2
# define ROTATE_L	123
# define ROTATE_R	124

//STRUCT//

typedef struct		s_sprxy
{
	double			x;
	double			y;
}					t_sprxy;

typedef struct		s_sprite
{
	int				nbspr;
	int				*order;
	double			*dist;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstartx;
	int				drawstarty;
	int				drawendy;
	int				drawendx;
	int				spritewidth;
	double			*zbuffer;
}					t_sprite;

typedef struct		s_texture
{
	int				texdir;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
}					t_texture;

typedef struct		s_ray
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			raydirx;
	double			raydiry;
	double			camerax;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;

	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			movespeed;
	double			rotspeed;
	int				x;
	int				texture;
}					t_ray;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				forward;
	int				back;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	int				minimapechelle;
	int				width;
	int				height;
	void			*img2;
	int				*addr2;
}                   t_data;

typedef struct  s_info
{
    char        **pc;
    char        **mapi;
    int         *found;
    int         *f;
    int         *c;
    int         full;
    int         color;
    int         ret;
    int         findmap;
    int         maperror;
    int         first;
    int         last;
    int         nl;
    int         getmap;
    int         spawn;
    int         x;
    int         y;
    int         toomuchspawn;
    int         line;
    int         col;
	t_data		texture[5];
	t_data		data;
	t_ray		ray;
	t_texture	t;
	t_sprite	s;
	t_sprxy	    *sxy;
}               t_info;

//FONCTIONS//
void            checkmap(char *map, t_info *info);
void            initinfo(t_info *info);
void    		initinfo2(t_info *info);
int             stockinfo(char *str, t_info *info);
int             findoc(char *str, char oc);
unsigned int    countnl(char *map);
int             beforeinfo(char *str, int p, int what);
int             verifycline(char *str);
int             tomap(char *str, t_info *info, int n);
int             stockmap(char *str, t_info *info);
int             checkspawn(char pos, int i, int j, t_info *info);
int             parsemap(char *map, t_info *info);

void			init2(t_info *info);
void			init3(t_info *info);
void			init_more(t_info *info);
void			init_texture(t_info *info);
void			init_sprite(t_info *info);
void			init_sprite2(t_info *info, int i, int j, int v);
void			init_dir(t_info *info);
int				init_mlx(t_info *info);
int				raycasting(t_info *info);
void			get_texture(t_info *info);
void			get_texture_adress(t_info *info);
void			stepsidedist(t_info *info);
void			incrementray(t_info *info);
void			drawstartend(t_info *info);
void			swap(t_info *info);

void			forward_back(t_info *info);
void			left_right(t_info *info);
void			rotate_right_left(t_info *info);
void			rotate_left(t_info *info, double olddirx);
int				key_press(int keycode, t_info *info);
int				key_release(int keycode, t_info *info);

int				color_column(t_info *info);
void			draw_texture(t_info *info, int x, int y);
void			draw_sprite(t_info *info, int y, int texx, int stripe);

void			dist_order2(t_info *info);
void			dist_order(t_info *info);
void			calculs(t_info *info, int i);
void			sprite(t_info *info);

void			error(t_info *info, char *str);
void			error2(t_info *info);
int				ft_exit(t_info *info);
void			verify_errors(t_info *info);

#endif