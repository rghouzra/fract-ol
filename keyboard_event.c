/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:12:40 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/22 11:26:01 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	third_keyboard_handler(int code, t_data *env);

int	handle_keyboard(int code, t_data *env)
{
	env->x = 0;
	env->y = 0;
	if (code == 53)
		ft_close(env);
	if (code == 8)
	{
		mlx_clear_window(env->ptr->mlx_ptr, env->ptr->mlx_win);
		env->color += 1;
		ft_draw(env, env->fractol);
	}
	if (code == 15)
	{
		mlx_clear_window(env->ptr->mlx_ptr, env->ptr->mlx_win);
		ft_init(env);
		ft_draw(env, env->fractol);
	}
	scnd_keyboard_handlera(code, env);
	return (0);
}

int	scnd_keyboard_handlera(int code, t_data *env)
{
	if (code == 35)
	{
		env->max_iteration += 20;
		ft_draw(env, env->fractol);
	}
	if (code == 46)
	{
		env->max_iteration -= 20;
		ft_draw(env, env->fractol);
	}
	if (code == 126)
	{
		env->ycenter += (20 * env->h) / env->height;
		ft_draw(env, env->fractol);
	}
	if (code == 125)
	{
		env->ycenter -= (20 * env->h) / env->height;
		ft_draw(env, env->fractol);
	}
	third_keyboard_handler(code, env);
	return (0);
}

int	third_keyboard_handler(int code, t_data *env)
{
	if (code == 124)
	{
		env->xcenter -= (20 * env->w) / env->width;
		ft_draw(env, env->fractol);
	}
	if (code == 123)
	{
		env->xcenter += (20 * env->w) / env->width;
		ft_draw(env, env->fractol);
	}
	return (0);
}
