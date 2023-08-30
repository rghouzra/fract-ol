/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:13:49 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/22 11:22:11 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_hook(int keycode, int x, int y, void *tmp)
{
	t_data	*data;

	data = (t_data *)tmp;
	if (keycode == 5)
	{
		data->xcenter = data->xcenter + (data->w * x) / data->width;
		data->ycenter = data->ycenter + (data->h * y) / data->height;
		data->w /= data->scale;
		data->h /= data->scale;
		data->max_iteration -= 25;
		ft_draw(data, data->fractol);
	}
	if (keycode == 4)
	{
		data->w *= data->scale;
		data->h *= data->scale;
		data->max_iteration += 25;
		data->xcenter = data->xcenter - (data->w * x) / data->width;
		data->ycenter = data->ycenter - (data->h * y) / data->height;
		ft_draw(data, data->fractol);
	}
	data->julia_ptr->move += (keycode == 1);
	return (0);
}

int	mouse_move(int x, int y, void *tmp)
{
	t_data	*data;

	data = (t_data *)tmp;
	if (data->julia_ptr->move % 2 == 0)
	{
		data->julia_ptr->img = data->julia_ptr->img;
		data->julia_ptr->rl = data->julia_ptr->rl;
	}
	else
	{
		if (x + y >= 0 && x <= data->width && y <= data->height)
		{
			data->julia_ptr->rl = data->xcenter - (data->w * x) / data->width;
			data->julia_ptr->img = data->ycenter - (data->h * y) / data->height;
			ft_draw(data, data->fractol);
		}
	}
	return (0);
}
