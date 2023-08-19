/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:22:41 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/19 14:56:26 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>

# define IMG_X 720
# define IMG_Y	640
# define IT_MAX	200

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	int		shift;
	double	julia_x;
	double	julia_y;
	int		which;
	double	tmp;
	double	z_r;
	double	z_i;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		zoom;
	char	**str;
	double	dist_x;
	double	dist_y;
}				t_data;

typedef struct p_data {
	int		win_x;
	int		win_y;
	int		is_m;
}				t_fract;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		is_mandelbrot(int x, int y, t_data *img);
int		is_julia(int x, int y, t_data *img);
int		color_key(int key_code, t_data *param);
void	julia(t_data *img, int shift);
void	mandelbrot(t_data *img, int shift);
int		color(int iter, int shift);
int		which_fract(char **str, int argc);
void	launcher(char **str, int argc);
double	ft_atod(char *str);
double	power(int c, int exp);
double	val_absolute(double c);
int		is_burning(int x, int y, t_data *img);
void	launch_fract(t_data *img);
int		mouse_destroy(t_data *img);
void	burning(t_data *img, int shift);
double	map(t_data img, int x, char c);
void	limits(t_data *img);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		zoom(int key_code, int x, int y, t_data *img);
int		zoomin(int x, int y, t_data *img);
int		ft_atoi(const char *str);
int		zoomout(int x, int y, t_data *img);
int		arrow_move(int key_code, t_data *img);
int		move(int key_code, int x, int y, t_data *img);
#endif
