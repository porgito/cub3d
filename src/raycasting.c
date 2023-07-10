/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:50:04 by jlaurent          #+#    #+#             */
/*   Updated: 2023/06/30 13:50:04 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_texture_adress(t_info *info)
{
	info->texture[0].addr = (int *)mlx_get_data_addr(info->texture[0].img,
			&info->texture[0].bits_per_pixel,
			&info->texture[0].line_length, &info->texture[0].endian);
//	info->texture[1].addr = (int *)mlx_get_data_addr(info->texture[1].img,
//			&info->texture[1].bits_per_pixel,
//			&info->texture[1].line_length, &info->texture[1].endian);
//	info->texture[2].addr = (int *)mlx_get_data_addr(info->texture[2].img,
//			&info->texture[2].bits_per_pixel,
//			&info->texture[2].line_length, &info->texture[2].endian);
//	info->texture[3].addr = (int *)mlx_get_data_addr(info->texture[3].img,
//			&info->texture[3].bits_per_pixel,
//			&info->texture[3].line_length, &info->texture[3].endian);
//	info->texture[4].addr = (int *)mlx_get_data_addr(info->texture[4].img,
//			&info->texture[4].bits_per_pixel,
//			&info->texture[4].line_length, &info->texture[4].endian);
	printf("test\n");
}

void	get_texture(t_info *info)
{
	int	w;
	int h;

	info->texture[0].img = mlx_xpm_file_to_image(info->data.mlx_ptr,info->pc[0], &w, &h);
	info->texture[1].img = mlx_xpm_file_to_image(info->data.mlx_ptr,info->pc[1], &w, &h);
	info->texture[2].img = mlx_xpm_file_to_image(info->data.mlx_ptr,info->pc[2], &w, &h);
	info->texture[3].img = mlx_xpm_file_to_image(info->data.mlx_ptr,info->pc[3], &w, &h);
//	info->texture[4].img = mlx_xpm_file_to_image(info->data.mlx_ptr,
//					info->sp, &(info->texture[4].width),
//					&(info->texture[4].height))))
	printf("before\n");
//	get_texture_adress(info);
	printf("texture ok \n");
}

int		raycasting(t_info *info)
{
	info->ray.x = 0;
	while (info->ray.x < HAUTEUR)
	{
		init3(info);
		stepsidedist(info);
		color_column(info);
		info->s.zbuffer[info->ray.x] = info->ray.perpwalldist;
		info->ray.x++;
	}
//	sprite(info);
	mlx_put_image_to_window(info->data.mlx_ptr, info->data.mlx_win,
			info->data.img, 0, 0);
	forward_back(info);
	left_right(info);
	rotate_right_left(info);
	swap(info);
	return (0);
}

int		init_mlx(t_info *info)
{
	init2(info);
	if (!(info->data.mlx_ptr = mlx_init()))
		error(info, "Mlx init impossible\n");
		printf("test\n");
	get_texture(info);
	info->data.img = mlx_new_image(info->data.mlx_ptr, HAUTEUR, LARGEUR);
	info->data.addr = (int *)mlx_get_data_addr(info->data.img, &info->data.
			bits_per_pixel, &info->data.line_length, &info->data.endian);
	info->data.mlx_win = mlx_new_window(info->data.mlx_ptr, HAUTEUR,
			LARGEUR, "cub3d");
	info->data.img2 = mlx_new_image(info->data.mlx_ptr, HAUTEUR, LARGEUR);
	info->data.addr2 = (int *)mlx_get_data_addr(info->data.img2, &info->
			data.bits_per_pixel, &info->data.line_length, &info->data.endian);
	mlx_hook(info->data.mlx_win, 33, 1L << 17, ft_exit, info);
	mlx_hook(info->data.mlx_win, 2, 1L << 0, key_press, info);
	mlx_loop_hook(info->data.mlx_ptr, raycasting, info);
	mlx_hook(info->data.mlx_win, 3, 1L << 1, key_release, info);
	mlx_loop(info->data.mlx_ptr);
	return (0);
}