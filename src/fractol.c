/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:37:43 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/11 13:53:16 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_data *img, int shift)
{
	c_data	cor;

	cor.win_y = 0;
	while (cor.win_y < IMG_Y)
	{
		cor.win_x = 0;
		while (cor.win_x < IMG_X)
		{
			cor.is_m = is_mandelbrot(cor.win_x, cor.win_y, img);
			if (cor.is_m == IT_MAX)
				my_mlx_pixel_put(img, cor.win_x, cor.win_y, 0);
			else
				my_mlx_pixel_put(img, cor.win_x,
					cor.win_y, color(cor.is_m, shift));
			cor.win_x++;
		}
		cor.win_y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	julia(t_data *img, int shift)
{
	c_data	cor;

	cor.win_y = 0;
	while (cor.win_y < IMG_Y)
	{
		cor.win_x = 0;
		while (cor.win_x < IMG_X)
		{
			cor.is_m = is_julia(cor.win_x, cor.win_y, img);
			if (cor.is_m == IT_MAX)
				my_mlx_pixel_put(img, cor.win_x, cor.win_y, 0);
			else
				my_mlx_pixel_put(img, cor.win_x,
					cor.win_y, color(cor.is_m, shift));
			cor.win_x++;
		}
		cor.win_y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	burning(t_data *img, int shift)
{
	c_data	cor;

	cor.win_y = 0;
	while (cor.win_y < IMG_Y)
	{
		cor.win_x = 0;
		while (cor.win_x < IMG_X)
		{
			cor.is_m = is_burning(cor.win_x, cor.win_y, img);
			if (cor.is_m == IT_MAX)
				my_mlx_pixel_put(img, cor.win_x, cor.win_y, 0x00000000);
			else
				my_mlx_pixel_put(img, cor.win_x,
					cor.win_y, color(cor.is_m, shift));
			cor.win_x++;
		}
		cor.win_y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
