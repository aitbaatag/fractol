/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:47:42 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/15 22:23:31 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_complex *c, int max_iter, t_data data_img)
{
	double		r;
	int			color;
	int			iter;
	t_complex	z;

	z.real = 0;
	z.imag = 0;
	iter = 0;
	while (iter < max_iter)
	{
		r = z.real;
		z.real = r * r - z.imag * z.imag + c->real;
		z.imag = 2.0 * r * z.imag + c->imag;
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
