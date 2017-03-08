/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:30:15 by mhalit            #+#    #+#             */
/*   Updated: 2017/03/06 20:48:21 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_select(int x, int y, t_fr *env)
{
	if (env->choice == 1)
		mandelbrot(env, x, y);
	else if (env->choice == 2)
		julia(env, x, y);
	else if (env->choice == 3)
		burningship(env, x, y);
	else
	{
		ft_putstr("usage: fractol mandelbrot = 1\njulia = 2\nburningship = 3");
		exit(42);
	}
}

void		fractol(t_fr *env)
{
	int		x;
	int		y;

	env->data = mlx_get_data_addr(env->img, &env->bpp,\
	&env->size_line, &env->endian);
	y = -1;
	while (++y < env->heigth)
	{
		x = -1;
		while (++x < env->width)
		{
			ft_select(x, y, env);
			pixel_image(x, y, env, env->color);
		}
	}
	mlx_put_image_to_window(env->init, env->win, env->img, 0, 0);
	mlx_string_put(env->init, env->win, 50, 50, 0x00FFFFF,\
	ft_strjoin("I = ", ft_itoa(env->iter)));
	env->otime = env->time / CLOCKS_PER_SEC * 10;
	env->time = clock();
}

void		mandelbrot(t_fr *env, int x, int y)
{
	if (env->basex == 0)
		env->basex = -0.5;
	env->pr = 1.5 * (x - env->width / 2) /
	(0.5 * env->zoom * env->width) + env->basex;
	env->pi = (y - env->heigth / 2) /
	(0.5 * env->zoom * env->heigth) + env->basey;
	env->zi = 0;
	env->zr = 0;
	env->i = -1;
	while (++env->i < env->iter)
	{
		env->ozr = env->zr;
		env->ozi = env->zi;
		env->zr = (env->ozr * env->ozr) - (env->ozi * env->ozi) + env->pr;
		env->zi = 2 * env->ozr * env->ozi + env->pi;
		if ((env->zr * env->zr) + (env->zi * env->zi) > 4)
			break ;
	}
}

void		julia(t_fr *env, int x, int y)
{
	if (env->pr == 0)
	{
		env->pr = -0.7 + env->basex;
		env->pi = 0.275015 + env->basey;
	}
	env->zr = 1.5 * (x - env->width / 2) /
	(0.5 * env->zoom * env->width) + env->basex;
	env->zi = (y - env->heigth / 2) /
	(0.5 * env->zoom * env->heigth) + env->basey;
	env->i = -1;
	while (++env->i < env->iter)
	{
		env->ozr = env->zr;
		env->ozi = env->zi;
		env->zr = (env->ozr * env->ozr) - (env->ozi * env->ozi) + env->pr;
		env->zi = 2 * env->ozr * env->ozi + env->pi;
		if ((env->zr * env->zr) + (env->zi * env->zi) > 4)
			break ;
	}
}

void		burningship(t_fr *env, int x, int y)
{
	if (env->basex == 0)
		env->basex = -0.5;
	env->pr = 1.5 * (x - env->width / 2) /
	(0.5 * env->zoom * env->width) + env->basex;
	env->pi = (y - env->heigth / 2) /
	(0.5 * env->zoom * env->heigth) + env->basey;
	env->zi = 0;
	env->zr = 0;
	env->i = -1;
	while (++env->i < env->iter)
	{
		env->ozr = env->zr;
		env->ozi = env->zi;
		env->zr = (env->ozr * env->ozr) - (env->ozi * env->ozi) + env->pr;
		env->zi = 2 * fabs(env->ozr * env->ozi) + env->pi;
		if ((env->zr * env->zr) + (env->zi * env->zi) > 4)
			break ;
	}
}
