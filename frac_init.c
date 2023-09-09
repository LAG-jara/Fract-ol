/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_vars(t_var *v)
{
	v->z.r = 0;
	v->z.i = 0;
	v->c.r = 0;
	v->c.i = 0;
	v->cur.r = 0;
	v->cur.i = 0;
	v->max.r = 0;
	v->max.i = 0;
	v->min.r = 0;
	v->min.i = 0;
	v->iter = DEF_ITER;
	v->ypos = WIN_H / 2;
	v->zpos = 1;
	v->lock_mov = 1;
	if (!v->jtype)
		v->jtype = 0;
	v->color_type = 0;
	v->xpos = WIN_W / 2;
	if (v->type == 1)
		v->xpos = WIN_W / 1.3;
	if (v->type == 3)
		v->xpos = WIN_W / 1.5;
}

void	start_vars(t_var *v)
{
	v->mlx_ptr = mlx_init();
	v->win_ptr = mlx_new_window(v->mlx_ptr, WIN_W, WIN_H, \
		"Fract-ol by alajara- ");
	init_vars(v);
	v->img_ptr = mlx_new_image(v->mlx_ptr, WIN_W, WIN_H);
	if (!v->mlx_ptr || !v->img_ptr)
		exit(1);
	v->addr = mlx_get_data_addr(v->img_ptr, &(v->bpp), &(v->line_len), \
			&(v->endian));
	v->width = WIN_W;
	v->height = WIN_H;
}

void	select_frac(t_var *v)
{
	if (v->type % 3 == 2)
		julia(v);
	else if (v->type % 3 == 0)
		ship(v);
	else
		mandelbrot(v);
}
//Z(n+1) = Z(0)^2 + 1;
