/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract_ol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:46:56 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/14 04:58:53 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fract *fract, t_data *img, t_mlx *mlx)
{
	fract->zoom = 1.0;
	fract->shift_x = 0;
	fract->shift_y = 0;
	fract->iter_plus = 0;
	mlx->mlx = mlx_init();
	if (!(mlx->mlx))
	{
		exit(1);
	}
	mlx->mlx_win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, fract->name);
	if (mlx->mlx_win == NULL)
		error_exit_free_mlx(fract);
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (img->img == NULL)
		error_exit_free_mlx(fract);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->addr == NULL)
	{
		error_exit_free_mlx(fract);
	}
	fract->ptr_mlx = mlx;
	fract->ptr_data = img;
}

void	init_julia(t_complex *julia, t_fract *fract, char *real, char *imag)
{
	julia->julia_real = ft_atoi(real);
	julia->julia_imag = ft_atoi(imag);
	fract->ptr_julia = julia;
}
