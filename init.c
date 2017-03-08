/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:51:36 by mhalit            #+#    #+#             */
/*   Updated: 2017/03/06 20:51:38 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init(t_fr **env)
{
	(*env)->heigth = 500;
	(*env)->width = 500;
	(*env)->init = mlx_init();
	(*env)->win = mlx_new_window((*env)->init,
	(*env)->heigth, (*env)->width, "Fract'ol");
	(*env)->img = mlx_new_image((*env)->init, (*env)->heigth, (*env)->width);
	(*env)->basex = 0;
	(*env)->basey = 0;
	(*env)->zoom = 1;
	(*env)->iter = 30;
	(*env)->color = 420;
	(*env)->time = 1;
	(*env)->pr = 0;
}
