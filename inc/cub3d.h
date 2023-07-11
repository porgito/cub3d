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

#include "../mlx/mlx.h"

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
# define ESC	53
# define SPEED		0.2
# define PI 		3.141592
# define X_SIDE 	0
# define Y_SIDE 	1
# define MINIMAP_S	10

//STRUCT//

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_texture
{
	t_img	img;
	char	*file_name;
	int		*colors;
	int		img_width;
	int		img_height;
}	t_texture;

typedef struct s_map
{
	int				height;
	int				width;
	char			*str;
	struct s_map	*next;
}	t_map;

typedef struct s_player
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	int		cur_x;
	int		cur_y;
	double	cam_x;
	double	raydir_x;
	double	raydir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		wall_id;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	tex_step;
}	t_ray;

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
    int         toomuchspawn;
    int         line;
    int         col;
	int			colorf;
	int			colorc;
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	p;
	int			map_x;
	int			map_y;
	double		pos_x;
	double		pos_y;
	double		angle;
	int			floor;
	int			ceiling;
	t_texture	texture[4];
}               t_info;

//FONCTIONS//
void            checkmap(char *map, t_info *info);
void            initinfo(t_info *info);
void    		initinfo2(t_info *info);
void			initinfo3(t_info *info, char *map_name);
static void		init_texture(t_info *info);
static void		init_dirplane(t_info *info, int idx);
void			init_player(t_info *info);
void			init_raycasting_info(t_info *info, t_ray *r, int x);
void			init_side_dist(t_info *info, t_ray *r);
void			init_perp_dist(t_info *info, t_ray *r);
void			init_draw_ypoints(t_ray *r);
static void		init_texture_info(t_info *info, char **texture, int texture_id);

int             stockinfo(char *str, t_info *info);
int             findoc(char *str, char oc);
unsigned int    countnl(char *map);
int             beforeinfo(char *str, int p, int what);
int             verifycline(char *str);
int             tomap(char *str, t_info *info, int n);
int             stockmap(char *str, t_info *info);
int             checkspawn(char pos, int i, int j, t_info *info);
int             parsemap(char *map, t_info *info);

void			my_mlx_pixel_put(t_info *info, int x, int y, int color);
static void		paint_bg(t_info *info);
static void		paint_walls(t_info *info, t_texture *texture, t_ray *r, int x);
static void		painting(t_info *info, t_ray *r, int x);
int				paint_map(t_info *info);
void			raycasting(t_info *info, t_ray *r);

static void		adjust_pos_range(t_info *info);
int				key_hook(int keycode, t_info *info);
void			move_up(t_info *info);
void			move_down(t_info *info);
void			move_left(t_info *info);
void			move_right(t_info *info);
void			rotate_left(t_info *info);
void			rotate_right(t_info *info);

static int		is_redrange(t_info *info, int w, int h);
static void		painting_minimap(t_info *info, int w, int h);
void			paint_minimap(t_info *info, int width, int height);


void			error(t_info *info, char *str);
void			error2(t_info *info);
int				ft_exit(t_info *info);
void			verify_errors(t_info *info);

#endif