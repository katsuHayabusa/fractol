/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:44:45 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/19 12:37:41 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoomout(int x, int y, t_data *img)
{
	double	center_x;
	double	center_y;
	double	mouse_x;
	double	mouse_y;

	img->zoom = 1;
	mouse_x = map(*img, x, 'x');
	mouse_y = map(*img, y, 'y');
	center_x = (img->x_min + img->x_max) / 2;
	center_y = (img->x_min + img->x_max) / 2;
	img->x_min = center_x + (img->x_min - center_x) * (img->zoom + 0.2);
	img->x_max = center_x + (img->x_max - center_x) * (img->zoom + 0.2);
	img->y_min = center_y + (img->y_min - center_y) * (img->zoom + 0.2);
	img->y_max = center_y + (img->y_max - center_y) * (img->zoom + 0.2);
	img->x_min -= (mouse_x - center_x) * 0.2;
	img->x_max -= (mouse_x - center_x) * 0.2;
	img->y_min -= (mouse_y - center_y) * 0.2;
	img->y_max -= (mouse_y - center_y) * 0.2;
	launch_fract(img);
	return (0);
}

int	zoomin(int x, int y, t_data *img)
{
	double	center_x;
	double	center_y;
	double	mouse_x;
	double	mouse_y;

	img->zoom = 1;
	mouse_x = map(*img, x, 'x');
	mouse_y = map(*img, y, 'y');
	center_x = (img->x_min + img->x_max) / 2;
	center_y = (img->x_min + img->x_max) / 2;
	img->x_min = center_x + (img->x_min - center_x) * (img->zoom - 0.2);
	img->x_max = center_x + (img->x_max - center_x) * (img->zoom - 0.2);
	img->y_min = center_y + (img->y_min - center_y) * (img->zoom - 0.2);
	img->y_max = center_y + (img->y_max - center_y) * (img->zoom - 0.2);
	img->x_min += (mouse_x - center_x) * 0.2;
	img->x_max += (mouse_x - center_x) * 0.2;
	img->y_min += (mouse_y - center_y) * 0.2;
	img->y_max += (mouse_y - center_y) * 0.2;
	launch_fract(img);
	return (0);
}

int	arrow_move(int key_code, t_data *img)
{
	double	dist_x;
	double	dist_y;

	if (key_code == 65361)
	{
		img->x_min -= (img->x_max - img->x_min / 100);
		img->x_max -= (img->x_max - img->x_min / 100);
	}
	if (key_code == 65362)
	{
		img->y_min -= (img->y_max - img->y_min / 100);
		img->y_max -= (img->y_max - img->y_min / 100);
	}
	if (key_code == 65363)
	{
		img->x_min += (img->x_max - img->x_min / 100);
		img->x_max += (img->x_max - img->x_min / 100);
	}
	if (key_code == 65364)
	{
		img->y_min += (img->y_max - img->y_min / 100);
		img->y_max += (img->y_max - img->y_min / 100);
	}
	launch_fract(img);
	return (0);
}
