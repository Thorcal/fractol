/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:59:43 by spuisais          #+#    #+#             */
/*   Updated: 2019/07/30 15:20:03 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_hud(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 5, 0xFFFFFF, "Esc         : Quit");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 20, 0xFFFFFF, "Arrow Keys  : Move");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 35, 0xFFFFFF, "Scroll      : Zoom in/out");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 50, 0xFFFFFF, "X/C         : Change color");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 65, 0xFFFFFF, "+/-         : Change Iterations");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 80, 0xFFFFFF, "I           : Mandelbrot");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 95, 0xFFFFFF, "O           : Julia");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 110, 0xFFFFFF, "P           : Tricorn");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 125, 0xFFFFFF, "[           : Burningship");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 140, 0xFFFFFF, "]           : Alienhand");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 155, 0xFFFFFF, "R           : Reset");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 170, 0xFFFFFF, "SPACE       : Stop Julia set");
}

void	ft_pixel_put(t_env *env, t_point pos, int color)
{
	int i;

	if (!(pos.x <= env->width && pos.x >= 0 &&
				pos.y <= env->height && pos.y >= 0))
		return ((void)NULL);
	i = env->line_size * pos.y + (pos.x * (env->bpp / 8));
	env->pxl[i] = (char)color;
	env->pxl[i + 1] = (char)(color >> 8);
	env->pxl[i + 2] = (char)(color >> 16);
}

void	usage_error(void)
{
	ft_putendl("Erreur.");
	ft_putstr("Usage = ./fractol ");
	ft_putendl("mandelbrot|julia|tricorn|burningship|alienhand");
	exit(0);
}

int		red_cross(t_env *env)
{
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	exit(0);
}

void	reset_vars(t_env *env)
{
	env->width = 1000;
	env->height = 1000;
	env->max_iter = 60;
	env->c_mult = 25;
	env->stopped = -1;
	env->c.r = 0.0;
	env->c.i = 0.0;
	env->start.x = 0.0;
	env->start.y = 0.0;
	env->r.min = -1.5;
	env->r.max = 0.7;
	env->i.min = -1.0;
	env->i.max = 1.0;
	env->zoom = 1.0;
	env->zoom_count.min = 0;
	env->zoom_count.max = 0;
	env->image = mlx_new_image(env->mlx_ptr, env->width, env->height);
	env->pxl = mlx_get_data_addr(env->image, &env->bpp,
			&env->line_size, &env->endian);
	draw_fractol(env);
}
