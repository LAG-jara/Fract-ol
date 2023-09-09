/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	b_n_w(t_var *v)
{
	if (v->iter >= v->count)
		return (BLACK);
	return (WHITE);
}

int	chess(t_var *v)
{
	if (v->iter >= v->count)
	{
		if (((v->col / 50) + (v->row / 50)) % 2)
			return (WHITE);
		return (BLACK);
	}
	return (RED);
}

int	shift(t_var *v)
{
	if (v->iter >= v->count)
	{
		if (v->count % 2)
			return (RED);
		return (PINK);
	}
	return (BLACK);
}

int	rgb(t_var *v)
{
	if (v->iter < v->count)
	{
		if (((v->col / 4) + (v->row / 4)) % 3 == 1)
			return (RED);
		if (((v->col / 4) + (v->row / 4)) % 3 == 2)
			return (GREEN);
		return (BLUE);
	}
	return (GRAY);
}

int	get_color(t_var *v)
{
	int	color;

	if (v->color_type % 4 == 0)
		color = b_n_w(v);
	if (v->color_type % 4 == 1)
		color = chess(v);
	if (v->color_type % 4 == 2)
		color = shift(v);
	if (v->color_type % 4 == 3)
		color = rgb(v);
	return (color);
}
