/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:54:47 by spuisais          #+#    #+#             */
/*   Updated: 2019/07/30 15:46:28 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <math.h>

int		find_mandelbrot(t_env env, t_point p1)
{
	int		i;
	t_ri	z;
	double	temp;
	double	cr;
	double	ci;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	cr = map_to_new(p1.x, env.width, env.r.min, env.r.max) + env.start.x;
	ci = map_to_new(p1.y, env.height, env.i.min, env.i.max) + env.start.y;
	while (i < env.max_iter && z.r * z.r + z.i * z.i < 4)
	{
		temp = z.r * z.r - z.i * z.i + cr;
		z.i = 2 * z.r * z.i + ci;
		z.r = temp;
		i++;
	}
	return (i);
}

int		find_julia(t_env env, t_point p1)
{
	int		j;
	double	temp;
	t_ri	z;

	j = 0;
	z.r = map_to_new(p1.x, env.width, env.r.min, env.r.max) + env.start.x;
	z.i = map_to_new(p1.y, env.height, env.i.min, env.i.max) + env.start.y;
	while (j < env.max_iter && z.r * z.r + z.i * z.i < 4)
	{
		temp = z.r * z.r - z.i * z.i + env.c.r;
		z.i = 2 * z.r * z.i + env.c.i;
		z.r = temp;
		j++;
	}
	if (j == env.max_iter)
		return (0);
	else
		return (j);
}

int		find_tricorn(t_env env, t_point p1)
{
	int		j;
	double	temp;
	t_ri	z;
	double	cr;
	double	ci;

	j = 0;
	z.r = 0.0;
	z.i = 0.0;
	cr = map_to_new(p1.x, env.width, env.r.min, env.r.max) + env.start.x;
	ci = map_to_new(p1.y, env.height, env.i.min, env.i.max) + env.start.y;
	while (j < env.max_iter && z.r * z.r + z.i * z.i < 4)
	{
		temp = z.r * z.r - z.i * z.i + cr;
		z.i = -2 * z.r * z.i + ci;
		z.r = temp;
		j++;
	}
	if (j == env.max_iter)
		return (0);
	else
		return (j);
}

int		find_burningship(t_env env, t_point p1)
{
	int		i;
	t_ri	z;
	double	temp;
	double	cr;
	double	ci;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	cr = map_to_new(p1.x, env.width, env.r.min, env.r.max) + env.start.x;
	ci = map_to_new(p1.y, env.height, env.i.min, env.i.max) + env.start.y;
	while (i < env.max_iter && z.r * z.r + z.i * z.i < 4)
	{
		temp = z.r * z.r - z.i * z.i + cr;
		z.i = fabsl(2 * z.r * z.i) + ci;
		z.r = fabs(temp);
		i++;
	}
	return (i);
}

int		find_alienhand(t_env env, t_point p1)
{
	int		j;
	double	temp;
	t_ri	z;

	j = 0;
	z.r = map_to_new(p1.x, env.width, env.r.min, env.r.max) + env.start.x;
	z.i = map_to_new(p1.y, env.height, env.i.min, env.i.max) + env.start.y;
	while (j < env.max_iter && z.r * z.r + z.i * z.i < 4)
	{
		temp = z.r * z.r - z.i * z.i + z.r;
		z.i = -2 * z.r * z.i + z.i;
		z.r = temp;
		j++;
	}
	if (j == env.max_iter)
		return (0);
	else
		return (j);
}
