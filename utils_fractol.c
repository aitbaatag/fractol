/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:47:47 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/14 05:13:22 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_free(int argc, int i)
{
	(void)argc;
	if (i == 1)
	{
		ft_putstr("Usage: fractol julia <c_real> <c_imag>\n");
		exit(1);
	}
	ft_putstr("Mandatory part\n");
	ft_putstr("Usage: fractol0 <fractal_type>\n");
	ft_putstr("Available fractal types: \"mandelbrot\" \"julia\"\n");
	ft_putstr("Bonus part\n");
	ft_putstr("Usage: fractol \"ship\"\n");
	exit(1);
}

int	is_digit(char num)
{
	int	i;

	i = 0;
	if ((num >= '0' && num <= '9'))
		return (1);
	return (0);
}

int	valid_input(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] == '.' || num[i] == '-' || num[i] == '+')
			i++;
		if (is_digit(num[i]) == 0)
		{
			error_free(0, 1);
		}
		i++;
	}
	return (1);
}
