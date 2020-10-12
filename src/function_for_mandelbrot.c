/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_for_mandelbrot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:19:03 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/28 20:19:06 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_var		init_malderbrot(void)
{
	t_var	var;

	var.x = 0;
	var.y = 0;
	var.re = 0;
	var.re2 = 0;
	var.im = 0;
	var.im2 = 0;
	var.zoom = SIZE / 4;
	var.x1 = -2.5;
	var.y1 = -1.8;
	var.iter = 0;
	var.max_iter = 255;
	var.colour = 265;
	return (var);
}

void		mandelbrot(t_window *win)
{
	double	tmp;

	win->var.im = win->var.x / win->var.zoom + win->var.x1;
	win->var.im2 = win->var.y / win->var.zoom + win->var.y1;
	win->var.re = 0;
	win->var.re2 = 0;
	win->var.iter = 0;
	while (win->var.re * win->var.re + win->var.re2 * win->var.re2 < 4 &&
			win->var.iter < win->var.max_iter)
	{
		tmp = win->var.re * win->var.re - win->var.re2 * win->var.re2 +
				win->var.im;
		win->var.re2 = 2.0 * win->var.re * win->var.re2 + win->var.im2;
		win->var.re = tmp;
		win->var.iter++;
	}
	fractol_paint(win);
	win->i++;
}
