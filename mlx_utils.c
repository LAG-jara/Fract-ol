/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	add_mlx_hook(t_var *v)
{
	mlx_hook(v->win_ptr, KEYPRESS, 0, read_key, v);
	mlx_hook(v->win_ptr, MOTIONNOTIFY, 0, mouse_hook, v);
	mlx_hook(v->win_ptr, BUTTONPRESS, 0, scroll_hook, v);
	mlx_hook(v->win_ptr, DESTROYNOTIFY, 0, exit_window, v);
}

void	my_put_pixel_img(t_var *v, int color)
{
	char	*dst;

	dst = v->addr + (v->row * v->line_len + v->col * (v->bpp / 8));
	*(unsigned int *) dst = color;
}
