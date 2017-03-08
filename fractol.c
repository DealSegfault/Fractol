/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:09:30 by mhalit            #+#    #+#             */
/*   Updated: 2017/03/06 20:42:31 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>

void		pixel_image(int x, int y, t_fr *env, int color)
{
	int		pos;

	pos = (x * env->bpp / 8) + (y * env->size_line);
	env->data[pos] = color * env->i;
	env->data[pos + 1] = (color >> 8) * env->i;
	env->data[pos + 2] = (color >> 16) * env->i;
}

int			mouse_slide(int x, int y, t_fr *env)
{
	if (env->pause == 0)
	{
		env->pr = ((double)x / (double)env->width);
		env->pi = ((double)y / (double)env->heigth);
		fractol(env);
	}
	return (0);
}

int			khook(int keycode, t_fr *env)
{
	if (keycode == 53)
		exit(42);
	else if (keycode == RIGHT || keycode == LEFT)
		env->basex += (keycode == LEFT ? 0.0006 : -0.0006) * IPS / env->zoom;
	else if (keycode == DOWN || keycode == UP)
		env->basey += (keycode == UP ? 0.0006 : -0.0006) * IPS / env->zoom;
	else if (keycode == PLUS || keycode == MINUS)
		keycode == PLUS ? env->zoom *= pow(1.001, IPS) :\
		(env->zoom /= pow(1.001, IPS));
	else if (keycode == IM || keycode == IP)
		keycode == IP ? env->iter *= 2 : (env->iter /= 2);
	else if (keycode == PAUSE)
		env->pause = env->pause == 1 ? 0 : 1;
	else if (keycode == 12)
		env->color += 10;
	else if (keycode && env)
		ft_putnbr(keycode);
	else
		return (0);
	fractol(env);
	return (0);
}

int			mhook(int keycode, int x, int y, t_fr *env)
{
	if (keycode == M_RIGHT || keycode == M_LEFT)
		env->basex += (keycode == M_LEFT ? 0.0006 : -0.0006) * IPS / env->zoom;
	else if (keycode == M_UP)
	{
		env->zoom *= pow(1.001, IPS);
		env->basex += (x - env->width / 2) / (env->width / 2 * env->zoom) / 8;
		env->basey += (y - env->heigth / 2) / (env->heigth / 2 * env->zoom) / 8;
	}
	else if (keycode == M_DOWN)
	{
		env->zoom /= pow(1.001, IPS);
		env->basex -= (x - env->width / 2) / (env->width / 2 * env->zoom) / 8;
		env->basey -= (y - env->heigth / 2) / (env->heigth / 2 * env->zoom) / 8;
	}
	else
		return (0);
	fractol(env);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fr *env;

	if (!(env = (t_fr *)malloc(sizeof(t_fr))))
		return (0);
	if (argc == 2)
	{
		init(&env);
		env->choice = atoi(argv[1]);
		fractol(env);
		mlx_key_hook(env->win, khook, env);
		mlx_mouse_hook(env->win, mhook, env);
		if (env->choice == 2)
			mlx_hook(env->win, MOTION, MASK, mouse_slide, env);
		mlx_loop(env->init);
	}
	else
		ft_putstr("usage: fractol mandelbrot = 1\njulia = 2\nburningship = 3");
}
