/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:30:06 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/22 11:28:41 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

#include <math.h>
#include "fractal.h"
#include <math.h>

#define PI 3.14159265

#include "fractal.h"
#include <math.h>

#define PI 3.14159265

#include "fractal.h"
#include <math.h>

#define PI 3.14159265

int ft_color(t_data *data)
{
    double ratio = (double)(data->iteration) / (double)data->max_iteration;
    double hue = fmod((ratio * 360.0 + data->color * 36.0), 360.0);
    double saturation = 1.0;
    double value = 1.0;

    double c = value * saturation;
    double x = c * (1 - fabs(fmod(hue / 60.0, 2) - 1));
    double m = value - c;

    double r, g, b;
    if (hue < 60) {
        r = c, g = x, b = 0;
    } else if (hue < 120) {
        r = x, g = c, b = 0;
    } else if (hue < 180) {
        r = 0, g = c, b = x;
    } else if (hue < 240) {
        r = 0, g = x, b = c;
    } else if (hue < 300) {
        r = x, g = 0, b = c;
    } else {
        r = c, g = 0, b = x;
    }

    r = (r + m) * 255;
    g = (g + m) * 255;
    b = (b + m) * 255;

    int color = ((int)r << 16) | ((int)g << 8) | (int)b;

    return color;
}