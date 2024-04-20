/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:31:15 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/14 06:13:27 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	generate_mandelbrot_colors(int iteration_level)
{
	double	x;
	int		red;
	int		blue;
	int		green;

	x = (double)iteration_level / MAX_ITER;
	red = (int)(9 * (1 - x) * x * x * x * 255);
	green = (int)(15 * (1 - x) * (1 - x) * x * x * 255);
	blue = (int)(9 * (1 - x) * (1 - x) * (1 - x) * x * 255);
	return ((red << 16) + (green << 8) + blue);
}
