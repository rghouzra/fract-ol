/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:13:15 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/21 15:57:46 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	julia(t_data *data)
{
	double			ca;
	double			cb;
	t_complex		point ;
	double			temp;

	cb = 0;
	ca = 0;
	data->iteration = 0;
	point = ft_map(data);
	ca = point.a;
	cb = point.b;
	while ((ca * ca + cb * cb) < 4 && data->iteration < data->max_iteration)
	{
		temp = ca;
		ca = ((ca * ca - cb * cb)) + data->julia_ptr->rl;
		cb = (2 * temp * cb) + data->julia_ptr->img;
		data->iteration++;
	}
	return (ft_color(data));
}
