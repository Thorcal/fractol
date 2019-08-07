/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:02:36 by spuisais          #+#    #+#             */
/*   Updated: 2019/07/30 15:48:45 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			ft_deal_key(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == 53)
		red_cross(env);
	if (key == 123)
		env->start.x -= 2 / (env->zoom * 200);
	if (key == 124)
		env->start.x += 2 / (env->zoom * 200);
	if (key == 125)
		env->start.y += 2 / (env->zoom * 200);
	if (key == 126)
		env->start.y -= 2 / (env->zoom * 200);
	if (key == 34)
		env->type = 1;
	if (key == 31)
		env->type = 2;
	ft_deal_key_2(key, env);
	draw_fractol(env);
	return (0);
}

int			ft_deal_key_2(int key, t_env *env)
{
	if (key == 35)
		env->type = 3;
	if (key == 33)
		env->type = 4;
	if (key == 30)
		env->type = 5;
	if (key == 7)
		env->c_mult -= 1;
	if (key == 8)
		env->c_mult += 1;
	if (key == 49)
		env->stopped *= -1;
	if (key == 69 && env->max_iter < 400)
		env->max_iter += 3;
	if (key == 78 && env->max_iter > 3)
		env->max_iter -= 3;
	if (key == 15)
		reset_vars(env);
	return (0);
}

int			mouse_pos(int x, int y, t_env *env)
{
	if (env->type != 2)
		return (0);
	if (env->stopped == 1)
		return (0);
	env->c.r = (long double)((long double)x / 1000) * 3.0;
	env->c.i = (long double)((long double)y / 1000) * 3.0;
	env->c.r -= 1.5;
	env->c.i -= 1.5;
	draw_fractol(env);
	return (0);
}

static void	ft_zoom(t_env *env, t_ri mouse)
{
	double interpolation;

	interpolation = 1.0 / env->zoom;
	env->r.min = mouse.r + ((env->r.min - mouse.r) * interpolation);
	env->r.max = mouse.r + ((env->r.max - mouse.r) * interpolation);
	env->i.min = mouse.i + ((env->i.min - mouse.i) * interpolation);
	env->i.max = mouse.i + ((env->i.max - mouse.i) * interpolation);
}

int			ft_deal_mouse(int button, int x, int y, void *param)
{
	t_env		*env;
	t_ri		m;

	env = (t_env *)param;
	m.r = (double)x / (env->width / (env->r.max - env->r.min)) + env->r.min;
	m.i = (double)y / (env->height / (env->i.max - env->i.min)) + env->i.min;
	if (button == 4)
		env->zoom_count.max = env->zoom;
	if (button == 5)
		env->zoom_count.min = env->zoom;
	if ((button == 4 && env->zoom < 1) || (button == 5 && env->zoom > 1))
		env->zoom = 1;
	if (button == 4)
		env->zoom *= 1.01;
	else if (button == 5)
		env->zoom /= 1.01;
	if (button == 4 || button == 5)
		ft_zoom(env, m);
	draw_fractol(env);
	return (0);
}
