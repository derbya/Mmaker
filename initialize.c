/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 17:03:57 by aderby            #+#    #+#             */
/*   Updated: 2017/08/25 15:04:06 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	initialize_hooks(t_e *env)
{
	mlx_hook(env->win, 2, 0, key_hook, env);
	mlx_hook(env->win, 3, 0, keyr_hook, env);
	mlx_hook(env->win, 4, 0, mousep_hook, env);
	mlx_hook(env->win, 5, 0, mouser_hook, env);
	mlx_hook(env->win, 6, 0, mousem_hook, env);
	mlx_hook(env->win, 12, 0, expose_hook, env);
	mlx_hook(env->win, 17, 0, exit_hook, env);
}

t_obj	*initialize_objs(void)
{
	t_obj		*o;
	static int	lia;

	o = (t_obj *)ft_memalloc(sizeof(t_obj));
	o->x = 0;
	o->y = 0;
	o->z = 0;
	o->w = 0;
	o->angle = 0;
	o->lia = lia;
	lia++;
	o->next = NULL;
	return (o);
}
t_img	*image_maker(void *mlx, int w, int h)
{
	t_img *i;
	i = (t_img *)ft_memalloc(sizeof(t_img));
	i->img = mlx_new_image(mlx, w, h);
	i->data = (int *)mlx_get_data_addr(i->img, &i->bbp, &i->size, &i->e);
	return (i);
}

t_e		*initialize_environment(void *mlx, int w, int h, char *title)
{
	t_e		*new;
	t_img	*img;

	new = (t_e *)ft_memalloc(sizeof(t_e));
	new->mlx = mlx;
	new->win = mlx_new_window(new->mlx, w, h, title);
	new->deleteme = 0;
	new->mouseb = 0;
	//IMGMALLOC;
	//CREATEIMG(new->mlx, w, h);
	//GETDATA;
	//SETIMG;
	//new->img = img;
	new->color = 0xFFFFFF;
	new->img = NULL;
	initialize_hooks(new);
	new->objs = initialize_objs();
	return (new);
}
