/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:09:20 by mhalit            #+#    #+#             */
/*   Updated: 2017/03/06 20:47:15 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <time.h>

typedef struct	s_fr
{
	void		*init;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			heigth;
	int			width;
	int			iter;
	int			choice;
	int			color;
	int			i;
	int			pause;
	double		zoom;
	double		basex;
	double		basey;
	double		zi;
	double		zr;
	double		ozr;
	double		ozi;
	double		pr;
	double		pi;
	double		otime;
	double		time;
}				t_fr;

# define MOTION 6
# define MASK (1L<<6)
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define IP 81
# define IM 75
# define M_UP 5
# define M_DOWN 4
# define M_LEFT 7
# define M_RIGHT 6
# define PLUS 69
# define MINUS 78
# define PAUSE 35
# define IPS env->otime

void			pixel_image(int x, int y, t_fr *env, int color);
int				khook(int keycode, t_fr *env);
int				mhook(int keycode, int x, int y, t_fr *env);
int				mouse_slide(int x, int y, t_fr *env);
int				main(int argc, char **argv);
void			mandelbrot(t_fr *env, int x, int y);
void			burningship(t_fr *env, int x, int y);
void			julia(t_fr *env, int x, int y);
void			ft_select(int x, int y, t_fr *env);
void			fractol(t_fr *env);
void			init(t_fr **env);

#endif
