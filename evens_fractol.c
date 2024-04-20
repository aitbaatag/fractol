/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evens_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:44:43 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/14 04:49:38 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	event_win(t_mlx *mlx, t_fract *fract, int n)
{
	if (n == 1)
		mlx_hook(mlx->mlx_win, 04, (1L << 2), burning_ship_zoom, fract);
	else
		mlx_hook(mlx->mlx_win, 04, (1L << 2), mandelbrot_zoom, fract);
	mlx_hook(mlx->mlx_win, 03, (1L << 1), events_key_win, fract);
	mlx_hook(mlx->mlx_win, 17, (1L << 17), error_exit_free_mlx, fract);
}

int	events_key_win(int keysym, t_fract *data_fract)
{
	if (keysym == 65307)
		error_exit_free_mlx(data_fract);
	else if (keysym == 65362)
		data_fract->shift_y += 0.1;
	else if (keysym == 65364)
		data_fract->shift_y -= 0.1;
	else if (keysym == 65361)
		data_fract->shift_x += 0.1;
	else if (keysym == 65363)
		data_fract->shift_x -= 0.1;
	else if (keysym == 65453)
		data_fract->iter_plus -= 10;
	else if (keysym == 65451)
		data_fract->iter_plus += 10;
	ft_creat_fractol(data_fract->ptr_data, data_fract->ptr_mlx, data_fract);
	return (0);
}
