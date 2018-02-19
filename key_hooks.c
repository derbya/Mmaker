/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:28:39 by aderby            #+#    #+#             */
/*   Updated: 2017/08/26 06:42:32 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	save_to_map(t_img *i, int fd)
{
	int		t;
	char	*str;

	t = 0;
	while (t < i->size / 4 * H)
	{
		str = ft_itoa(i->data[t]);
		ft_putstr_fd(str, fd);
		ft_putstr_fd("  ", fd);
		t++;
	}
}

/*int		*load_map(t_e *e)
{
	char	**maplist;
	char	*str;
	int		*img;
	int		i;

	i = 0;
	str = (char *)ft_memalloc(sizeof(char) * H * W * 6 + 1);
	if (!e->fd)
		e->fd = open("map", O_RDONLY);
	if ((read(e->fd, str, 2000000000) < 0))
		ft_putstr("read\n");
	maplist = ft_strsplit(str, ' ');
	while (maplist[i])
	{
		img[i] = ft_atoi(maplist[i]);
		i++;
	}
	free(str);
	close(e->fd);
	return (img);
}*/

int		key_hook(int keycode, t_e *e)
{
	ft_putnbr(keycode);
	if (keycode == 53)
		exit(0);
	/*if (keycode == 13)
		e->objs->y += 5;
	if (keycode == 0)
		e->objs->x += 5;
	if (keycode == 1)
		e->objs->y -= 5;
	if (keycode == 2)
		e->objs->x -= 5;
	if (keycode == 124)
		(e->objs->angle *= 1.05) % 360;
	if (keycode == 123)
		(e->objs->angle *= 0.95) % 360;
	mlx_clear_window(e->mlx, e->win);
	draw_objs(e);*/
	if (keycode == 11)
		e->color = 175 << 8 | 255;
	if (keycode == 15)
		e->color = 255 << 16 | 35 << 8;
	if (keycode == 5)
		e->color = 255 << 8 | 130;
	if (keycode == 18)
		e->fd = open("map", O_CREAT | O_RDWR);
	if (keycode == 19)
		save_to_map(e->img, e->fd);
	if (keycode == 20)
	{
		e->img->data = load_map(e);
		mlx_clear_window(e->mlx, e->win);
	}
	return (keycode);
}

int		keyr_hook(int keycode, t_e *e)
{
	ft_putnbr(keycode);
	return (keycode);
}

int		expose_hook(t_e *e)
{
	return (0);
}

int		exit_hook(t_e *e)
{
	exit(0);
}
