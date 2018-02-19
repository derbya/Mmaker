/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:57:20 by aderby            #+#    #+#             */
/*   Updated: 2017/08/26 06:40:04 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	pixel_to_image(t_img *i, int x, int y, int color)
{
	int t;

	if (x < 0 || x > W || y < 0 || y > H)
		return ;
	t = (x) + (y * i->size / 4);
	i->data[t] = color;
}

void	draw_objs(t_e *e)
{
	int l;

	if (!e->img)
		e->img = image_maker(e->mlx, W, H);	
	l = e->objs->x;
	while (l <= e->objs->x + e->objs->w)
	{
		pixel_to_image(e->img, l, e->objs->y, 0xFFFFFF);
		l++;
	}
/*	l = e->objs->x;
	while (l <= e->objs->x + e->objs->w)
	{
		pixel_to_image(e->img, l, e->objs->y + 20, 0xFFFFFF);
		l++;
	}*/
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img->img);
	e->img = NULL;
}

void	fill_objs(t_e *e)
{
	e->objs->x = W / 2;
	e->objs->y = H / 2;
	e->objs->angle = 0;
	e->objs->w = 200;
}

void	fill_grid(t_img *i, int x, int y, int color)
{
	int lx;
	int ly;

	lx = x + 9;
	ly = y + 9;
	while (y <= ly)
	{
		x = lx - 9;
		while (x <= lx)
		{
			pixel_to_image(i, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_grid(t_e *e)
{
	int x;
	int y;

	y = 0;
	e->img = image_maker(e->mlx, W, H);
	while (y < H)
	{
		x = 0;
		while (x <= W)
		{
			if (x % 64 == 0 || y % 64 == 0)
				pixel_to_image(e->img, x, y, 0x252525);
			x++;
		}
		y++;
	}
}

int		main(void)
{
	t_e		*e;
	void	*mlx;
	//char	*image;
	int		x;
	int		y;
	int		i;

	i = 0;
	mlx = mlx_init();
	e = initialize_environment(mlx, W, H, "Wolf3d");
	//image = (char *)mlx_xpm_file_to_image(mlx, av[1], &x, &y);
	//mlx_put_image_to_window(mlx, e->win, image, 0, 0);
//	fill_objs(e);
//	draw_objs(e);
	draw_grid(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	mlx_loop(mlx);
}
