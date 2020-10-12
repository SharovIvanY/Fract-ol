/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:18:29 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/28 20:18:32 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			fractol_while(t_window *win)
{
	win->i = 0;
	win->var.y = 0;
	while (win->var.y < SIZE)
	{
		win->var.x = 0;
		while (win->var.x < SIZE)
		{
			if (win->type_fractol == 1)
				mandelbrot(win);
			else if (win->type_fractol == 2)
				julia(win);
			else if (win->type_fractol == 3)
				myfrac(win);
			else if (win->type_fractol == 4)
				burningship(win);
			win->var.x++;
		}
		win->var.y++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}

void			fractol_paint(t_window *win)
{
	if (win->var.iter == win->var.max_iter)
		win->data[win->i] = win->back_colour;
	else
		win->data[win->i] = win->var.colour * win->var.iter;
}

void			fractol_loop(t_window *win)
{
	fractol_while(win);
	mlx_hook(win->win, 2, 0, key_press, win);
	mlx_hook(win->win, 17, 0, close, win);
	mlx_hook(win->win, 17, 0, expose, win);
	mlx_hook(win->win, 4, 0, (void *)mouse_key, win);
	mlx_hook(win->win, 6, 0, (void *)julia_mouse, win);
	mlx_loop(win->mlx);
}

void			fractol_initialization(t_window *win)
{
	if (win->type_fractol == 1)
		win->var = init_malderbrot();
	else if (win->type_fractol == 2)
		win->var = init_julia();
	else if (win->type_fractol == 3)
		win->var = init_myfrac();
	else if (win->type_fractol == 4)
		win->var = init_burning_ship();
}

int				main(int argc, char **argv)
{
	t_window	*win;

	if (argc != 2)
		what_usage();
	win = initialization_win(argv[1]);
	fractol_initialization(win);
	fractol_loop(win);
}
