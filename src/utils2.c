#include "../inc/cub3d.h"

void	stepsidedist(t_info *info)
{
	if (info->ray.raydirx < 0)
	{
		info->ray.stepx = -1;
		info->ray.sidedistx = (info->ray.posx - info->ray.mapx) \
							* info->ray.deltadistx;
	}
	else
	{
		info->ray.stepx = 1;
		info->ray.sidedistx = (info->ray.mapx + 1.0 - info->ray.posx) \
							* info->ray.deltadistx;
	}
	if (info->ray.raydiry < 0)
	{
		info->ray.stepy = -1;
		info->ray.sidedisty = (info->ray.posy - info->ray.mapy) \
							* info->ray.deltadisty;
	}
	else
	{
		info->ray.stepy = 1;
		info->ray.sidedisty = (info->ray.mapy + 1.0 - info->ray.posy) \
							* info->ray.deltadisty;
	}
	incrementray(info);
}

void	incrementray(t_info *info)
{
	while (info->ray.hit == 0)
	{
		if (info->ray.sidedistx < info->ray.sidedisty)
		{
			info->ray.sidedistx += info->ray.deltadistx;
			info->ray.mapx += info->ray.stepx;
			info->ray.side = 0;
		}
		else
		{
			info->ray.sidedisty += info->ray.deltadisty;
			info->ray.mapy += info->ray.stepy;
			info->ray.side = 1;
		}
		if (info->mapi[info->ray.mapx][info->ray.mapy] == '1')
			info->ray.hit = 1;
	}
	drawstartend(info);
}

void	drawstartend(t_info *info)
{
	if (info->ray.side == 0)
		info->ray.perpwalldist = ((double)info->ray.mapx - \
				info->ray.posx + (1 - (double)info->ray.
				stepx) / 2) / info->ray.raydirx;
	else
		info->ray.perpwalldist = ((double)info->ray.mapy - \
				info->ray.posy + (1 - (double)info->ray.
				stepy) / 2) / info->ray.raydiry;
	info->ray.lineheight = (int)(LARGEUR / info->ray.perpwalldist);
	info->ray.drawstart = -info->ray.lineheight / 2 + LARGEUR / 2;
	if (info->ray.drawstart < 0)
		info->ray.drawstart = 0;
	info->ray.drawend = info->ray.lineheight / 2 + LARGEUR / 2;
	if (info->ray.drawend >= LARGEUR || info->ray.drawend < 0)
		info->ray.drawend = LARGEUR - 1;
}

void	swap(t_info *info)
{
	void *tmp;

	tmp = info->data.img;
	info->data.img = info->data.img2;
	info->data.img2 = tmp;
	tmp = info->data.addr;
	info->data.addr = info->data.addr2;
	info->data.addr2 = tmp;
}