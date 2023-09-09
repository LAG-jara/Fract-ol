/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_var *v)
{
	v->tmp = 0;
	v->row = -1;
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	while (++v->row < v->height)
	{
		v->col = -1;
		v->cur.i = (v->row - v->ypos) * 3.0f / (v->zpos * WIN_H);
		while (++v->col < v->width)
		{
			v->cur.r = (v->col - v->xpos) * 3.0f / (v->zpos * WIN_W);
			v->count = -1;
			v->z.r = 0;
			v->z.i = 0;
			while (v->count++ < v->iter && \
				((v->z.r * v->z.r) + (v->z.i * v->z.i) <= 4.0f))
			{
				v->tmp = (v->z.r * v->z.r) - (v->z.i * v->z.i) + v->cur.r;
				v->z.i = 2 * v->z.r * v->z.i + v->cur.i;
				v->z.r = v->tmp;
			}
			my_put_pixel_img(v, get_color(v));
		}
	}
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img_ptr, 0, 0);
}

void	julia_set(t_var *v)
{
	if (v->jtype % 5 == 0)
	{
		v->c.r = -0.79;
		v->c.i = 0.15;
	}
	else if (v->jtype % 5 == 2)
	{
		v->c.r = -0.162;
		v->c.i = 1.04;
	}
	else if (v->jtype % 5 == 3)
	{
		v->c.r = 0.28;
		v->c.i = 0.008;
	}
	else if (v->jtype % 5 == 4)
	{
		v->c.r = -1.476;
		v->c.i = 0;
	}
	else
	{
		v->c.r = 0.3;
		v->c.i = -0.01;
	}
}

void	julia(t_var *v)
{
	v->tmp = 0;
	v->row = -1;
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	julia_set(v);
	while (++v->row < v->height)
	{
		v->col = -1;
		while (++v->col < v->width)
		{
			v->z.r = (v->col - v->xpos) * 3.0f / (v->zpos * WIN_W);
			v->z.i = (v->row - v->ypos) * 3.0f / (v->zpos * WIN_H);
			v->count = -1;
			while (v->count++ < v->iter && \
				((v->z.r * v->z.r) + (v->z.i * v->z.i) <= 4.0f))
			{
				v->tmp = (v->z.r * v->z.r) - (v->z.i * v->z.i) + v->c.r;
				v->z.i = 2 * v->z.r * v->z.i + v->c.i;
				v->z.r = v->tmp;
			}
			my_put_pixel_img(v, get_color(v));
		}
	}
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img_ptr, 0, 0);
}

void	ship(t_var *v)
{
	v->tmp = 0;
	v->row = -1;
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	while (++v->row < v->height)
	{
		v->col = -1;
		v->cur.i = (v->row - v->ypos) * 3.0f / (v->zpos * WIN_H);
		while (++v->col < v->width)
		{
			v->cur.r = (v->col - v->xpos) * 3.0f / (v->zpos * WIN_W);
			v->count = -1;
			v->z.r = 0;
			v->z.i = 0;
			while (v->count++ < v->iter && \
				((v->z.r * v->z.r) + (v->z.i * v->z.i) <= 4.0f))
			{
				v->tmp = (v->z.r * v->z.r) - (v->z.i * v->z.i) + v->cur.r;
				v->z.i = fabs(2 * v->z.r * v->z.i + v->cur.i);
				v->z.r = fabs(v->tmp);
			}
			my_put_pixel_img(v, get_color(v));
		}
	}
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img_ptr, 0, 0);
}
