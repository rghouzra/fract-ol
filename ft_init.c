/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:26:03 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/22 14:33:18 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_init(t_data *data)
{
	data->color = 0;
	data->max_iteration = 50;
	data->xcenter = 2;
	data->ycenter = 2;
	data->width = 800;
	data->height = 800;
	data->h = 4.00;
	data->w = 4.00;
	data->scale = 0.5;
	data->julia_ptr->move = 0;
	data->julia_ptr->rl = 0;
	data->julia_ptr->img = -0.8;
}
