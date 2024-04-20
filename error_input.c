/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:44:40 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/15 23:04:13 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error_exit_free_mlx(t_fract *ptr)
{
	mlx_destroy_image(ptr->ptr_mlx->mlx, ptr->ptr_data->img);
	mlx_destroy_window(ptr->ptr_mlx->mlx, ptr->ptr_mlx->mlx_win);
	mlx_destroy_display(ptr->ptr_mlx->mlx);
	free(ptr->ptr_mlx->mlx);
	exit(0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
