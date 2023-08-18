/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:23:05 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/18 16:30:43 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	which_fract(char **str, int argc)
{
	if (str[1] == NULL)
	{
		printf("Invalid input\n");
		printf("Fractals :\njulia  mandelbrot  burningship\n");
		return (-1);
	}
	if (ft_strncmp(str[1], "mandelbrot", 10) == 0 && argc == 2)
		return (1);
	if (ft_strncmp(str[1], "julia", 5) == 0 && (argc == 4 || argc == 2))
		return (2);
	if (ft_strncmp(str[1], "burningship", 11) == 0 && argc == 2)
		return (3);
	else
	{
		printf("Invalid input\n");
		printf("Fractals :\njulia  mandelbrot  burningship\n");
	}
	return (0);
}

void	launch_fract(t_data *img)
{
	if (img->which == 1)
		mandelbrot(img, img->shift);
	if (img->which == 2)
	{
		if (!img->str[2] || !img->str[3])
		{
			img->julia_x = 0.3;
			img->julia_y = 0.5;
			julia(img, img->shift);
		}
		else
		{
			img->julia_x = ft_atod(img->str[2]);
			img->julia_y = ft_atod(img->str[3]);
			julia(img, img->shift);
		}
	}
	if (img->which == 3)
		burning(img, img->shift);
}

void	launcher(char **str, int argc)
{
	t_data	img;

	img.which = which_fract(str, argc);
	img.str = str;
	if (img.which <= 0)
		return ;
	limits(&img);
	img.shift = 48;
	img.zoom = 1;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, IMG_X, IMG_Y, "Fractol");
	img.img = mlx_new_image(img.mlx, IMG_X, IMG_Y);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	launch_fract(&img);
	mlx_hook(img.mlx_win, 2, 1L << 0, color_key, &img);
	mlx_hook(img.mlx_win, 17, 1L << 0, mouse_destroy, &img);
	mlx_mouse_hook(img.mlx_win, zoom, &img);
	mlx_loop(img.mlx);
}
