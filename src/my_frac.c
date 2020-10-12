/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_frac.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:19:41 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/28 20:19:42 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_var		init_myfrac(void)
{
	t_var var;

	var.x = 0;
	var.y = 0;
	var.re = 0;
	var.re2 = 0;
	var.im = 0.29;
	var.im2 = 0.02;
	var.zoom = SIZE / 4;
	var.x1 = -2;
	var.y1 = -2;
	var.iter = 0;
	var.max_iter = 140;
	var.colour = 0xf9542b;
	return (var);
}

void		myfrac(t_window *win)
{
	double tmp;

	win->var.re = win->var.x / win->var.zoom + win->var.x1;
	win->var.re2 = win->var.y / win->var.zoom + win->var.y1;
	win->var.iter = 0;
	while (win->var.re * win->var.re + win->var.re2 * win->var.re2 < 4 &&
			win->var.iter < win->var.max_iter)
	{
		tmp = win->var.re;
		win->var.re = win->var.re * win->var.re - win->var.re2 * win->var.re2 +
				win->var.im;
		win->var.re2 = 2 * win->var.re2 * tmp + win->var.im2;
		win->var.iter++;
	}
	fractol_paint(win);
	win->i++;
}
