/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_init_and_exit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:19:17 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/28 20:19:19 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			what_usage(void)
{
	ft_printf("./fractol [usage: mandelbrot, julia, ship or myfrac]\n");
	exit(0);
}

static int		check_name(char *name)
{
	int			i;

	i = -1;
	while (name[++i])
		name[i] = tolower(name[i]);
	if (!ft_strcmp(name, "mandelbrot") ||
	!ft_strcmp(name, "1"))
		return (1);
	else if (!ft_strcmp(name, "julia") ||
	!ft_strcmp(name, "2"))
		return (2);
	else if (!ft_strcmp(name, "myfrac") ||
	!ft_strcmp(name, "3"))
		return (3);
	else if (!ft_strcmp(name, "burningship") ||
	!ft_strcmp(name, "ship") || !ft_strcmp(name, "4"))
		return (4);
	what_usage();
	return (0);
}

t_window		*initialization_win(char *name)
{
	t_window	*win;
	int			size_line;
	int			bpp;
	int			endian;

	if (!(win = (t_window*)malloc(sizeof(t_window))))
		exit(0);
	size_line = SIZE * SIZE;
	bpp = 8;
	endian = 0;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, SIZE, SIZE, "fractol");
	win->img = mlx_new_image(win->mlx, SIZE, SIZE);
	win->data = (int *)mlx_get_data_addr(win->img, &bpp, &size_line, &endian);
	win->i = 0;
	win->type_fractol = check_name(name);
	win->flag_mouse = 0;
	win->back_colour = 0xFFFFFF;
	return (win);
}

int				change_colour(t_window *win)
{
	if (win->back_colour == 0x000000)
		return (0x0000FF);
	else if (win->back_colour == 0x0000FF)
		return (0x00FF00);
	else if (win->back_colour == 0x00FF00)
		return (0x00FFFF);
	else if (win->back_colour == 0x00FFFF)
		return (0xFF0000);
	else if (win->back_colour == 0xFF0000)
		return (0xFF00FF);
	else if (win->back_colour == 0xFF00FF)
		return (0xFFFF00);
	else if (win->back_colour == 0xFFFF00)
		return (0xFFFFFF);
	else if (win->back_colour == 0xFFFFFF)
		return (0x000000);
	return (0);
}

int				expose(void *param)
{
	t_window	*win;

	win = param;
	exit(0);
}
