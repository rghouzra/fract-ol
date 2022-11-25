/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:12:21 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/21 15:55:28 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_complex	ft_map(t_data *data)
{
	t_complex		point;

	point.a = ((data->w * data->x) / data->width - data->xcenter);
	point.b = ((data->h * data->y) / data->height - data->ycenter);
	return (point);
}
