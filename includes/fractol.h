/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:20:47 by spuisais          #+#    #+#             */
/*   Updated: 2019/07/31 13:22:04 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include "../libft/includes/libft.h"
# define THREADS		4
# define NUM_FRACTALS	5
# define WIDTH			1000
# define HEIGHT			1000

typedef	struct		s_dpoint
{
	long double		min;
	long double		max;
}					t_dpoint;

typedef	struct		s_point
{
	long double		x;
	long double		y;
}					t_point;

typedef	struct		s_ri
{
	long double		r;
	long double		i;
}					t_ri;

typedef struct		s_env
{
	int				width;
	int				height;
	int				type;
	int				c_mult;
	int				stopped;
	t_ri			c;
	t_dpoint		r;
	t_dpoint		i;
	t_point			start;
	long double		zoom;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image;
	char			*pxl;
	int				bpp;
	int				line_size;
	int				endian;
	int				max_iter;
	t_dpoint		zoom_count;
}					t_env;

typedef struct		s_threads
{
	t_env			*env;
	int				id;
}					t_threads;

void				reset_vars(t_env *env);
void				render(t_env *env, int index);
void				usage_error(void);
void				ft_pixel_put(t_env *env, t_point pos, int color);
int					find_mandelbrot(t_env env, t_point p1);
int					find_julia(t_env env, t_point p1);
int					find_tricorn(t_env env, t_point p1);
int					find_burningship(t_env env, t_point p1);
int					find_alienhand(t_env env, t_point p1);
int					red_cross(t_env *env);
int					ft_deal_key(int key, void *param);
int					ft_deal_key_2(int key, t_env *env);
int					ft_deal_mouse(int button, int x, int y, void *param);
int					mouse_pos(int x, int y, t_env *env);
double				map_to_new(int i, int size, double min, double max);
void				init_hud(t_env *env);
int					init_vars(t_env *env);
void				draw_fractol(t_env *env);

#endif
