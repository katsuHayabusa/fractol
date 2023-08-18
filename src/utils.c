/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:58:36 by saichaou          #+#    #+#             */
/*   Updated: 2023/08/18 11:02:36 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgb(int r, int g, int b, int shift)
{
	shift = shift - '0';
	return ((r + shift * 50) << 16 | (g + shift * 50) << 8 | (b + shift * 50));
}

int	color(int iter, int shift)
{
	int	pal[6];

	(void) shift;
	pal[0] = rgb(135, 206, 235, shift);
	pal[1] = rgb(46, 204, 113, shift);
	pal[2] = rgb(255, 127, 80, shift);
	pal[3] = rgb(148, 0, 211, shift);
	pal[4] = rgb(244, 196, 48, shift);
	pal[5] = rgb(255, 182, 193, shift);
	return ((pal[iter % 6]));
}

double	power(int c, int exp)
{
	int	res;

	res = c;
	while (exp)
	{
		res *= c;
		exp--;
	}
	return (res);
}

double	ft_atod(char *str)
{
	double	sign;
	double	res;
	int		i;

	sign = 1;
	while (*str == ' ' || (*str >= 7 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '-' || *str == '+')
		str++;
	res = ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		res += (*str - '0') / power(10, i);
		str++;
		i++;
	}
	return (res * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
