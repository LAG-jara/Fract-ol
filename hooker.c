/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_info(t_var *v)
{
	ft_printf("=-*-= I N F O =-*-=\nFractal: \t%d\nIteration:\t%d\nColor:\t\t%d\
\nJulia_type:\t%d\n", v->type % 3, v->iter, v->color_type % 4, v->jtype % 5);
}

int	read_key(int press_key, t_var *v)
{
	if (press_key == KEY_ESC)
		exit_window(v);
	else if (press_key == KEY_LEFT || press_key == KEY_A)
		v->xpos += 20.0;
	else if (press_key == KEY_RIGHT || press_key == KEY_D)
		v->xpos -= 20.0;
	else if (press_key == KEY_UP || press_key == KEY_W)
		v->ypos += 20.0;
	else if (press_key == KEY_DOWN || press_key == KEY_S)
		v->ypos -= 20.0;
	else if (press_key == KEY_MIN && v->iter >= 2)
		v->iter -= 2;
	else if (press_key == KEY_PLU)
		v->iter += 2;
	else if (press_key == KEY_Q)
		v->color_type += 1;
	else if (press_key == KEY_E)
		v->type += 1;
	else if (press_key == KEY_J)
		v->jtype += 1;
	else if (press_key == KEY_I)
		print_info(v);
	select_frac(v);
	return (0);
}

int	mouse_hook(int x, int y, t_var *v)
{
	if (x < WIN_W && x >= 0 && y < WIN_H && y >= 0 && v->lock_mov == 1)
	{
		v->cur.r = (x - v->xpos) * 3.0 / (v->zpos * WIN_W);
		v->cur.i = (y - v->ypos) * 3.0 / (v->zpos * WIN_H);
	}
	if (v->lock_mov == 1)
		select_frac(v);
	return (0);
}

int	scroll_hook(int button, int x, int y, t_var *v)
{
	if (button == SCRL_U)
	{
		v->zpos /= 1.1;
		x = x - v->xpos;
		y = y - v->ypos;
		v->xpos -= ((x / 1.1) - x);
		v->ypos -= ((y / 1.1) - y);
	}
	else if (button == SCRL_D)
	{
		v->zpos *= 1.1;
		x = x - v->xpos;
		y = y - v->ypos;
		v->xpos -= ((x * 1.1) - x);
		v->ypos -= ((y * 1.1) - y);
	}
	if (button == M_L_BUTT)
		v->lock_mov *= -1;
	if (v->lock_mov == 1 || button == SCRL_U || button == SCRL_D)
		select_frac(v);
	return (0);
}

int	exit_window(t_var *v)
{
	if (v)
		mlx_destroy_window(v->mlx_ptr, v->win_ptr);
	exit(EXIT_SUCCESS);
}
