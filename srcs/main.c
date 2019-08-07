/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:11:04 by spuisais          #+#    #+#             */
/*   Updated: 2019/07/30 15:57:57 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	map_to_new(int i, int size, double min, double max)
{
	double	range;

	range = max - min;
	return (i * (range / size) + min);
}

int		select_fractal(t_env *env, t_point p1)
{
	int n;

	n = 0;
	if (env->type == 1)
		n = find_mandelbrot(*env, p1);
	else if (env->type == 2)
		n = find_julia(*env, p1);
	else if (env->type == 3)
		n = find_tricorn(*env, p1);
	else if (env->type == 4)
		n = find_burningship(*env, p1);
	else if (env->type == 5)
		n = find_alienhand(*env, p1);
	else
		red_cross(env);
	return (n);
}

void	render(t_env *env, int t_index)
{
	t_point p1;
	int		rgb;
	int		n;

	p1.y = (t_index * (env->height / THREADS) - 1);
	while (++p1.y < (env->height / THREADS) * (t_index + 1))
	{
		p1.x = -1;
		while (++p1.x < env->width)
		{
			n = select_fractal(env, p1);
			rgb = (n * 10 * env->c_mult % 256);
			rgb = (rgb << 8) + (n * env->c_mult % 256);
			rgb = (rgb << 8) + (n * 50 * env->c_mult % 256);
			ft_pixel_put(env, p1, rgb);
		}
	}
}

int		init_vars(t_env *env)
{
	env->width = WIDTH;
	env->height = HEIGHT;
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
	if (!(env->mlx_ptr = mlx_init()))
		return (-1);
	if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, env->width,
		env->height, "Fractol")))
		return (-1);
	env->image = mlx_new_image(env->mlx_ptr, env->width, env->height);
	env->pxl = mlx_get_data_addr(env->image, &env->bpp,
			&env->line_size, &env->endian);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_env		env;

	if (argc != 2)
		usage_error();
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		env.type = 1;
	else if (ft_strcmp(argv[1], "julia") == 0)
		env.type = 2;
	else if (ft_strcmp(argv[1], "tricorn") == 0)
		env.type = 3;
	else if (ft_strcmp(argv[1], "burningship") == 0)
		env.type = 4;
	else if (ft_strcmp(argv[1], "alienhand") == 0)
		env.type = 5;
	else
		usage_error();
	if (init_vars(&env) != 0)
		exit(0);
	draw_fractol(&env);
	mlx_hook(env.win_ptr, 6, 0, mouse_pos, &env);
	mlx_hook(env.win_ptr, 2, 0, ft_deal_key, &env);
	mlx_hook(env.win_ptr, 17, 0, red_cross, &env);
	mlx_mouse_hook(env.win_ptr, ft_deal_mouse, (void*)&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
