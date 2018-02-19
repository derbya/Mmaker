/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:24:21 by aderby            #+#    #+#             */
/*   Updated: 2017/08/25 15:04:55 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		mousep_hook(int keycode, int x, int y, t_e *e)
{
	e->mouseb = 1;
	return (keycode);
}

int		mouser_hook(int keycode, int x, int y, t_e *e)
{
	e->mouseb = 0;
	return (keycode);
}

int		mousem_hook(int x, int y, t_e *e)
{
	x /= 10;
	y /= 10;
	x *= 10;
	y *= 10;
	if (x > 0 && y > 0)
	{
		if (e->mouseb)
		{
			fill_grid(e->img, x, y, e->color);
		mlx_clear_window(e->mlx, e->win);
		mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
		}
	}
	return (x);
}
