/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:47:39 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/14 05:18:04 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_args(char *str, int argc)
{
	if (argc == 2)
	{
		if (!(ft_strcmp(str, "mandelbrot")))
			return (1);
		else if (!(ft_strcmp(str, "ship")))
			return (1);
	}
	if (argc == 4)
	{
		if (!(ft_strcmp(str, "julia")))
		{
			return (1);
		}
	}
	else
		error_free(argc, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx		mlx;
	t_data		data_img;
	t_complex	julia;
	t_fract		fract;

	fract.name = argv[1];
	if (check_args(argv[1], argc))
	{
		if (argc == 4 && check_args(argv[1], argc)
			&& (valid_input(argv[2])) == 1 && (valid_input(argv[3])) == 1)
			init_julia(&julia, &fract, argv[2], argv[3]);
		else if (!(ft_strcmp(argv[1], "ship")))
		{
			fractol_init(&fract, &data_img, &mlx);
			event_win(&mlx, &fract, 1);
			ft_creat_fractol(&data_img, &mlx, &fract);
			mlx_loop(mlx.mlx);
		}
		fractol_init(&fract, &data_img, &mlx);
		event_win(&mlx, &fract, 0);
		ft_creat_fractol(&data_img, &mlx, &fract);
		mlx_loop(mlx.mlx);
	}
	else
		error_free(argc, 0);
}
