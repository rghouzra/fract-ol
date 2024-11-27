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
    const int FIXED_POINT_SHIFT = 16;
    const int FIXED_POINT_MULTIPLIER = 1 << FIXED_POINT_SHIFT;

    int64_t ca_fixed = (int64_t)(point.a * FIXED_POINT_MULTIPLIER);
    int64_t cb_fixed = (int64_t)(point.b * FIXED_POINT_MULTIPLIER);
    int64_t point_a_fixed = ca_fixed;
    int64_t point_b_fixed = cb_fixed;
    data->iteration = 0;
    while ((ca_fixed * ca_fixed + cb_fixed * cb_fixed) < 
           (4 * FIXED_POINT_MULTIPLIER) && 
           data->iteration < data->max_iteration) {
        int64_t temp = ca_fixed;
        ca_fixed = ((ca_fixed * ca_fixed - cb_fixed * cb_fixed) >> FIXED_POINT_SHIFT) + point_a_fixed;
        cb_fixed = ((2 * temp * cb_fixed) >> FIXED_POINT_SHIFT) + point_b_fixed;
        data->iteration++;
    }
    return ft_color(data);
}
