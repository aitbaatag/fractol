/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:59:16 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/14 04:59:16 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_complex *c, int max_iter, t_data data_img, t_complex julia)
{
	double		r;
	int			color;
	int			iter;
	t_complex	z;

	z.real = c->real;
	z.imag = c->imag;
	iter = 0;
	while (iter < max_iter)
	{
		r = z.real;
		z.real = r * r - z.imag * z.imag + julia.julia_real;
		z.imag = 2.0 * r * z.imag + julia.julia_imag;
		if ((z.real * z.real) + (z.imag * z.imag) >= 4.0)
		{
			color = generate_mandelbrot_colors(iter);
			my_mlx_pixel_put(&data_img, c->pixelx, c->pixely, color);
			return ;
		}
		iter++;
	}
	my_mlx_pixel_put(&data_img, c->pixelx, c->pixely, 0);
}
