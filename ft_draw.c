/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:32:57 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/21 15:49:51 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_draw(t_data *data, int (*function)(t_data *data))
{
	data->x = 0;
	while (data->x < data->width)
	{
		data->y = 0;
		while (data->y < data->height)
		{
			my_mlx_pixel_put(data, data->x, data->y, function(data));
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->ptr->mlx_ptr, data->ptr->mlx_win, \
		data->img, 0, 0);
}
