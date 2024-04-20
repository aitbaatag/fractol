/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:47:45 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/14 05:09:34 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(int *)dst = color;
}

t_point	map(int pixelX, int pixelY)
{
	t_point	result;
	double	xpercent;
	double	ypercent;
	double	newx;
	double	newy;

	xpercent = (double)pixelX / WIDTH;
	ypercent = (double)pixelY / HEIGHT;
	newx = MINCOORDX + (MAXCOORDX - MINCOORDX) * xpercent;
	newy = MINCOORDY + (MAXCOORDY - MINCOORDY) * ypercent;
	result = (t_point){newx, newy};
	return (result);
}
