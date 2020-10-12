/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_key_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:19:34 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/28 20:19:36 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			key_press_two(int key, void *fdf)
{
	t_window	*win;

	win = fdf;
	if (key == MAIN_PAD_1)
	{
		win->type_fractol = 1;
		fractol_initialization(win);
	}
	if (key == MAIN_PAD_2)
	{
		win->type_fractol = 2;
		fractol_initialization(win);
	}
	if (key == MAIN_PAD_3)
	{
		win->type_fractol = 3;
		fractol_initialization(win);
	}
	if (key == MAIN_PAD_4)
	{
		win->type_fractol = 4;
		fractol_initialization(win);
	}
}

int				key_press(int key, void *fdf)
{
	t_window	*win;

	win = fdf;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == SPACE)
		win->back_colour = change_colour(win);
	if (key == ARROW_UP)
		win->var.y1 += 30 / win->var.zoom;
	if (key == ARROW_DOWN)
		win->var.y1 -= 30 / win->var.zoom;
	if (key == ARROW_LEFT)
		win->var.x1 += 30 / win->var.zoom;
	if (key == ARROW_RIGHT)
		win->var.x1 -= 30 / win->var.zoom;
	if (key == MAIN_PAD_1 || key == MAIN_PAD_2 || key == MAIN_PAD_3 ||
	key == MAIN_PAD_4)
		key_press_two(key, fdf);
	mlx_clear_window(win->mlx, win->win);
	fractol_while(win);
	return (0);
}

void			zoom_in_or_out(int keys, int x, int y, t_window *win)
{
	double		past_x;
	double		past_y;

	if (keys == 4 || keys == 5)
	{
		past_x = (x / win->var.zoom + win->var.x1);
		past_y = (y / win->var.zoom + win->var.y1);
		if (keys == 4)
			win->var.zoom *= 1.3;
		else
			win->var.zoom /= 1.3;
		win->var.x1 = past_x - (x / win->var.zoom);
		win->var.y1 = past_y - (y / win->var.zoom);
		mlx_clear_window(win->mlx, win->win);
		fractol_while(win);
	}
}

void			mouse_key(int keys, int x, int y, t_window *win)
{
	if (keys == 1)
	{
		if (win->flag_mouse == 1)
			win->flag_mouse = 0;
		else
			win->flag_mouse = 1;
	}
	if (keys == 4 || keys == 5)
		zoom_in_or_out(keys, x, y, win);
}

void			julia_mouse(int x, int y, t_window *win)
{
	if (win->flag_mouse == 1)
	{
		win->var.im2 = (double)(x - (double)SIZE / 2) / ((double)SIZE / 2);
		win->var.im = (double)(y - (double)SIZE / 2) / ((double)SIZE / 2);
		mlx_clear_window(win->mlx, win->win);
		fractol_while(win);
	}
}
