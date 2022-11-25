/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:13:00 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/21 15:43:22 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	exit_with_print(char *s)
{
	ft_putstr(s, 2);
	exit(1);
}

char	*title_win(int option)
{
	if (option == 1)
		return ("julia");
	else if (option == 2)
		return ("mandelbrot");
	else if (option == 3)
		return ("p_burning_ship");
	return ("fractol");
}
