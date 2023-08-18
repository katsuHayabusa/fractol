/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:18:11 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/11 18:33:19 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_julia(int x, int y, t_data *img)
{
	int		i;
	double	tmp;
	double	c_r;
	double	c_i;

	img->z_r = map(*img, x, 'x');
	img->z_i = map(*img, y, 'y');
	c_i = img->julia_x;
	c_r = img->julia_y;
	i = 0;
	while ((img->z_r * img->z_r) + (img->z_i * img->z_i) < 4 && i < IT_MAX)
	{
		tmp = img->z_r;
		img->z_r = img->z_r * img->z_r - img->z_i * img->z_i + c_r;
		img->z_i = 2 * img->z_i * tmp + c_i;
		i++;
	}
	return (i);
}

int	is_mandelbrot(int x, int y, t_data *img)
{
	int		i;
	double	tmp;
	double	c_r;
	double	c_i;

	c_r = map(*img, x, 'x');
	c_i = map(*img, y, 'y');;
	img->z_r = 0;
	img->z_i = 0;
	i = 0;
	while ((img->z_r * img->z_r) + (img->z_i * img->z_i) < 4 && i < IT_MAX)
	{
		tmp = img->z_r;
		img->z_r = img->z_r * img->z_r - img->z_i * img->z_i + c_r;
		img->z_i = 2 * img->z_i * tmp + c_i;
		i++;
	}
	return (i);
}

int	is_burning(int x, int y, t_data *img)
{
	int		i;
	double	tmp;
	double	c_r;
	double	c_i;

	c_r = map(*img, x, 'x');
	c_i = map(*img, y, 'y');
	img->z_r = 0;
	img->z_i = 0;
	i = 0;
	while ((img->z_r * img->z_r) + (img->z_i * img->z_i) < 4 && i < IT_MAX)
	{
		tmp = img->z_r;
		img->z_r = img->z_r * img->z_r - img->z_i * img->z_i + c_r;
		img->z_i = 2 * img->z_i * tmp + c_i;
		i++;
		img->z_i = val_absolute(img->z_i);
		img->z_r = val_absolute(img->z_r);
	}
	return (i);
}

