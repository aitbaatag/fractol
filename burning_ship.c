/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:28:30 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/14 04:29:00 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//zn+1 = (|Re(zn)| + i|Im(zn)|)2 + c
void	burning_ship(t_complex *c, int max_iter, t_data data_img)
{
	double		r;
	int			color;
	int			iter;
	t_complex	z;

	z.real = 0.0;
	z.imag = 0.0;
	iter = 0;
	while (iter <= max_iter)
	{
		r = z.real * z.real - z.imag * z.imag + c->real;
		z.imag = fabs(2.0 * z.real * z.imag) + c->imag;
		z.real = r;
		if (z.imag * z.imag + z.real * z.real >= 4.0)
		{
			color = generate_mandelbrot_colors(iter);
			my_mlx_pixel_put(&data_img, c->pixelx, c->pixely, color);
			return ;
		}
		iter++;
	}
	my_mlx_pixel_put(&data_img, c->pixelx, c->pixely, 0);
}
