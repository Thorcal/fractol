/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:21:07 by spuisais          #+#    #+#             */
/*   Updated: 2019/07/31 14:43:12 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*ft_thread(void *data)
{
	t_threads *t;

	t = (t_threads*)data;
	render(t->env, t->id);
	pthread_exit(NULL);
}

void	draw_fractol(t_env *env)
{
	pthread_t	t_id[THREADS];
	t_threads	t[THREADS];
	int			i;

	i = -1;
	while (++i < THREADS)
	{
		t[i].env = env;
		t[i].id = i;
		if ((pthread_create(&t_id[i], NULL, ft_thread, &t[i])) == -1)
			return ;
	}
	i = -1;
	while (++i < THREADS)
		if (pthread_join(t_id[i], NULL))
			return ;
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->image, 0, 0);
	init_hud(env);
}
