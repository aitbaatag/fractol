/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fract_ol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:44:08 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/14 07:03:36 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_zoom(int button, int x, int y, t_fract *ptr)
{
	(void)x;
	(void)y;
	if (button == 4)
		ptr->zoom *= 1.1;
	else if (button == 5)
		ptr->zoom /= 1.1;
	ft_creat_fractol(ptr->ptr_data, ptr->ptr_mlx, ptr);
	return (0);
}

int	burning_ship_zoom(int button, int x, int y, t_fract *ptr)
{
	double	mouse_x;
	double	mouse_y;
	t_point	point;

	point = map(x, y);
	mouse_x = point.x * ptr->zoom + ptr->shift_x;
	mouse_y = point.y * ptr->zoom + ptr->shift_y;
	if (button == 4)
	{
		ptr->zoom *= 1.1;
		ptr->shift_x = mouse_x - point.x * ptr->zoom;
		ptr->shift_y = mouse_y - point.y * ptr->zoom;
	}
	else if (button == 5)
	{
		ptr->zoom /= 1.1;
		ptr->shift_x = mouse_x - point.x * ptr->zoom;
		ptr->shift_y = mouse_y - point.y * ptr->zoom;
	}
	ft_creat_fractol(ptr->ptr_data, ptr->ptr_mlx, ptr);
	return (0);
}

void	ft_creat_fractol(t_data *data_img, t_mlx *mlx, t_fract *fract)
{
	t_point		point;
	t_complex	c;

	c.pixely = 0.0;
	while (c.pixely < HEIGHT)
	{
		c.pixelx = 0.0;
		while (c.pixelx < WIDTH)
		{
			point = map(c.pixelx, c.pixely);
			c.real = (point.x * fract->zoom) + fract->shift_x;
			c.imag = (point.y * fract->zoom) + fract->shift_y;
			if (!ft_strcmp(fract->name, "mandelbrot"))
				mandelbrot(&c, MAX_ITER + fract->iter_plus, *data_img);
			else if (!ft_strcmp(fract->name, "julia"))
				julia(&c, MAX_ITER + fract->iter_plus,
					*data_img,*fract->ptr_julia);
			else if (!ft_strcmp(fract->name, "ship"))
				burning_ship(&c, MAX_ITER + fract->iter_plus, *data_img);
			c.pixelx++;
		}
		c.pixely++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, data_img->img, 0, 0);
}
