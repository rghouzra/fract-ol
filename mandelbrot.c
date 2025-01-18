/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:12:51 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/21 15:48:44 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mandelbrot(t_data *data)
{
	double			ca;
	double			cb;
	t_complex		point;
	double			temp;

	data->iteration = 0;
	point = ft_map(data);
	ca = point.a;
	cb = point.b;
	while ((ca * ca + cb * cb) < 4 && data->iteration < data->max_iteration)
	{
		temp = ca;
		ca = ((ca * ca - cb * cb) + point.a);
		cb = (2 * temp * cb + point.b);
		data->iteration++;
	}
	return (ft_color(data));
}