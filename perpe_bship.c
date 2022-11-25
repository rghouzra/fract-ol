/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perpe_bship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:20:28 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/22 11:21:46 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	ft_abs(double z)
{
	if (z < 0)
		return (-z);
	return (z);
}

int	perpe_burning_ship(t_data *data)
{
	double		ca;
	double		cb;
	t_complex	point;
	double		temp;

	data->iteration = 0;
	point = ft_map(data);
	ca = point.a;
	cb = point.b;
	while ((ca * ca + cb * cb) < 4 && data->iteration < data->max_iteration)
	{
		temp = ca;
		ca = ((ca * ca - cb * cb) + point.a);
		cb = (2 * temp * cb + point.b);
		cb = -ft_abs(cb);
		data->iteration++;
	}
	return (ft_color(data));
}
