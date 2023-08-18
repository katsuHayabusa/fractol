/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:12:42 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/18 16:31:15 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_key(int key_code, t_data *img)
{
	if (key_code == 65307)
	{
		mlx_loop_end(img ->mlx);
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_window(img->mlx, img->mlx_win);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		exit(0);
	}
	if (key_code >= 48 && key_code <= 53)
	{
		img->shift = key_code;
		if (img->which == 1)
			mandelbrot(img, key_code);
		if (img->which == 2)
			julia(img, key_code);
		if (img->which == 3)
			burning(img, key_code);
	}
	arrow_move(key_code, img);
	return (0);
}

int	mouse_destroy(t_data *img)
{
	mlx_loop_end(img->mlx);
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(0);
	return (0);
}

int	zoom(int key_code, int x, int y, t_data *img)
{
	if (key_code == 4)
		zoomin(x, y, img);
	if (key_code == 5)
		zoomout(x, y, img);
	return (0);
}
