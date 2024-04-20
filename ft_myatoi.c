/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myatoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:46:34 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/14 04:53:53 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_sg(char *str)
{
	int		i;
	double	sg;

	i = 0;
	sg = 1;
	while (((str[i] >= 9 && str[i] <= 13)) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sg *= -1.0;
		i++;
	}
	return (sg);
}

double	ft_atoi(char *str)
{
	int		i;
	double	num;
	double	var;

	var = 0.1;
	num = 0.0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] == '.')
		{
			i++;
			while (str[i] >= '0' && str[i] <= '9')
			{
				num += (str[i++] - '0') * var;
				var *= 0.1;
			}
			break ;
		}
		num = num * 10.0 + str[i] - '0';
		i++;
	}
	return (num * ft_sg(str));
}
