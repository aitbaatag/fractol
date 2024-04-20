/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:50:05 by kait-baa          #+#    #+#             */
/*   Updated: 2024/02/15 21:56:26 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 122
# define MINCOORDX -2.0
# define MAXCOORDX 2.0
# define MINCOORDY -2.0
# define MAXCOORDY 2.0

typedef struct s_point
{
	double		x;
	double		y;
}				t_point;
typedef struct s_complex
{
	double		real;
	double		imag;
	double		julia_real;
	double		julia_imag;

	int			pixelx;
	int			pixely;
}				t_complex;
typedef struct mlx
{
	void		*mlx;
	void		*mlx_win;
}				t_mlx;
typedef struct s_data
{
	char		*name;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;
typedef struct s_fract_ol
{
	char		*name;
	double		zoom;
	double		shift_x;
	double		shift_y;
	int			iter_plus;
	t_mlx		*ptr_mlx;
	t_complex	*ptr_julia;
	t_data		*ptr_data;
}				t_fract;
int				ft_strcmp(const char *str1, const char *str2);
void			ft_putstr(char *str);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			mandelbrot(t_complex *c, int max_iter, t_data data_img);
void			ft_creat_fractol(t_data *data_img, t_mlx *mlx, t_fract *fract);
void			fractol_init(t_fract *fract, t_data *img, t_mlx *mlx);
int				mandelbrot_zoom(int button, int x, int y, t_fract *ptr);
int				error_exit_free_mlx(t_fract *fract);
void			event_win(t_mlx *mlx, t_fract *fract, int n);
int				events_key_win(int keysym, t_fract *data_fract);
void			julia(t_complex *c, int max_iter, t_data data_img,
					t_complex julia);
double			ft_atoi(char *str);
int				generate_mandelbrot_colors(int iteration_level);
void			error_free(int argc, int i);
int				valid_input(char *num);
void			init_julia(t_complex *julia, t_fract *fract, char *real,
					char *imag);
void			burning_ship(t_complex *c, int max_iter, t_data data_img);
int				burning_ship_zoom(int button, int x, int y, t_fract *ptr);
t_point			map(int pixelX, int pixelY);
#endif