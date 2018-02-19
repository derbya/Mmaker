/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:58:50 by aderby            #+#    #+#             */
/*   Updated: 2017/08/25 15:02:34 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/inc/libft.h"
# include "miniLibx/mlx.h"
# include <fcntl.h>

# define FILLADDR img->img, &img->bbp, &img->size, &img->e
# define FILLDATA mlx_get_data_addr(FILLADDR)
# define DATA img->data
# define GETDATA DATA = FILLDATA
# define IMG img->img
# define SETIMG IMG = img
# define NEWIMG(x, y, z) IMG = mlx_new_image(x, y, z)
# define CREATEIMG(x, y, z) IMG = NEWIMG(x, y, z)
# define IMGMALLOC (img = (t_img *)ft_memalloc(sizeof(t_img)))
# define H 1000
# define W 1000

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				bbp;
	int				size;
	int				e;
	struct s_img	*next;
}					t_img;

typedef struct		s_obj
{
	int				x;
	int				y;
	int				z;//might not even use
	int				w;
	double			angle;
	int				lia;
	struct s_obj	*next;
}					t_obj;

typedef struct 		s_e
{
	void			*mlx;
	void			*win;
	int				deleteme;
	int				color;
	int				fd;
	int				mouseb;
	struct s_img	*img;
	struct s_obj	*objs;
}					t_e;

t_e					*initialize_environment(void *mlx, int w, int h, char *title);
void				pixel_to_image(t_img *i, int x, int y, int color);
void				initialize_hooks(t_e *env);
t_obj				*initialize_objs(void);
void				draw_objs(t_e *e);
void				fill_grid(t_img *i, int x, int y, int color);
t_img				*image_maker(void *mlx, int w, int h);
int					key_hook(int keycode, t_e *e);
int					keyr_hook(int keycode, t_e *e);
int					expose_hook(t_e *e);
int					exit_hook(t_e *e);
int					mousep_hook(int keycode, int x, int y, t_e *e);
int					mouser_hook(int keycode, int x, int y, t_e *e);
int					mousem_hook(int x, int y, t_e *e);

#endif
