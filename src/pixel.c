/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:07:16 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/18 16:07:45 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	map(t_data img, int x, char c)
{
	if (c == 'x')
		return (img.x_min + (double) x / IMG_X * (img.x_max - img.x_min));
	if (c == 'y')
		return (img.y_min + (double) x / IMG_Y * (img.y_max - img.y_min));
	return (0);
}

void	limits(t_data *img)
{
	if (img->which == 1)
	{	
		img->x_min = -2.1;
		img->x_max = 0.6;
		img->y_min = -1.2;
		img->y_max = 1.2;
	}
	if (img->which == 2)
	{
		img->x_min = -2;
		img->x_max = 2;
		img->y_min = -2;
		img->y_max = 2;
	}
	if (img->which == 3)
	{
		img->x_min = -2;
		img->x_max = 2;
		img->y_min = -2;
		img->y_max = 2;
	}
}
