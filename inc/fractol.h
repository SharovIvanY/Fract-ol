/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:31:07 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/28 20:31:08 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYFRACTAL_FRACTOL_H
# define MYFRACTAL_FRACTOL_H

# include "../lib/libft/inc/ft_printf.h"
# include "keycode.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# define SIZE 900
# include <stdio.h>

typedef struct		s_var
{
	int				y;
	int				x;
	double			re;
	double			im;
	double			re2;
	double			im2;
	double			zoom;
	double			x1;
	double			y1;
	int				iter;
	int				max_iter;
	int				colour;
}					t_var;

typedef struct		s_window
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int				i;
	int				type_fractol;
	int				flag_mouse;
	int				back_colour;
	t_var			var;
}					t_window;

t_var				init_malderbrot();
void				mandelbrot(t_window *win);

t_var				init_julia(void);
void				julia(t_window *win);

t_var				init_burning_ship(void);
void				burningship(t_window *win);

t_var				init_myfrac(void);
void				myfrac(t_window *win);

void				what_usage();
t_window			*initialization_win(char *name);
void				fractol_while(t_window *win);
void				fractol_paint(t_window *win);
void				fractol_initialization(t_window *win);
int					expose(void *param);
int					key_press(int key, void *fdf);
void				zoom_in_or_out(int keys, int x, int y, t_window *win);
void				mouse_key(int keys, int x, int y, t_window *win);
void				julia_mouse(int x, int y, t_window *win);
int					change_colour(t_window *win);

#endif
