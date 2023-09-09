/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:55:06 by alajara-          #+#    #+#             */
/*   Updated: 2023/06/08 19:54:39 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "macro.h"
# include "libft.h"
# include <math.h>

//	-=-=-=|STRUCTS|=-=-=-	//

typedef struct s_coordinates
{
	double	r;
	double	i;
}	t_cmplx;

typedef struct s_var
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;

	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;

	int		type;
	int		jtype;
	t_cmplx	z;
	t_cmplx	c;
	t_cmplx	cur;
	t_cmplx	max;
	t_cmplx	min;
	double	tmp;
	int		count;
	int		iter;
	int		col;
	int		row;
	double	xpos;
	double	ypos;
	double	zpos;
	int		lock_mov;
	int		color_type;
}	t_var;

//	-=-=-=|FUNCTIONS|=-=-=-	//

void	start_vars(t_var *v);
void	add_mlx_hook(t_var *v);
void	my_put_pixel_img(t_var *v, int color);
void	select_frac(t_var *vars);
int		read_key(int press_key, t_var *v);
int		mouse_hook(int x, int y, t_var *v);
int		scroll_hook(int button, int x, int y, t_var *v);
int		exit_window(t_var *v);

void	mandelbrot(t_var *v);
void	julia(t_var *v);
void	ship(t_var *v);

void	calc_frac(t_var *v);
int		get_color(t_var *v);

#endif