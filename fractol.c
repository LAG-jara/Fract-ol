/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2021/11/04 22:17:00 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_args(int ac, char **av, t_var *v)
{
	v->type = 0;
	if (ac == 2 || ac == 3)
	{
		av[1][0] = ft_tolower(av[1][0]);
		if (!ft_strncmp(av[1], "1", 2) || !ft_strncmp(av[1], "mandelbrot", 11))
			v->type = 1;
		if (!ft_strncmp(av[1], "2", 2) || !ft_strncmp(av[1], "julia", 6))
			v->type = 2;
		if (!ft_strncmp(av[1], "3", 2) || !ft_strncmp(av[1], "ship", 5))
			v->type = 3;
	}
	if (ac == 3 && v->type == 2)
		v->jtype = ft_atoi(av[2]);
	if (!v->type || ((ac != 2) && !(ac == 3 && v->type == 2)))
	{
		ft_printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		ft_printf("|You can write the following flags🚩|\n");
		ft_printf("| like this: ./fract-ol <3>or<Ship> |\n");
		ft_printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
		ft_printf("\t1 | Mandelbrot\n\t2 | Julia <0-4 for variations>\n\t3 | \
Ship\n\n\t-Controls-\n\n\tQ\t| Colors\n\tE\t| Fractals\n\tJ\t| Julia sets\n\t\
+\t| More Iterations\n\t-\t| Less Iterations\n\tW S A D\t| Move\n\t\
Scroll\t| Zoom\n\tI\t| Debug_info\n\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_var	vars;

	check_args(ac, av, &vars);
	start_vars(&vars);
	select_frac(&vars);
	add_mlx_hook(&vars);
	mlx_loop(vars.mlx_ptr);
}
