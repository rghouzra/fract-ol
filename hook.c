/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:12:30 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/21 15:21:57 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_close(t_data *param)
{
	mlx_destroy_image(param->ptr->mlx_ptr, param->img);
	mlx_destroy_window(param->ptr->mlx_ptr, param->ptr->mlx_win);
	free(param->julia_ptr);
	free(param);
	exit(1);
	return (1);
}

void	ft_hook_event(t_list *fractal, t_data *data)
{
	mlx_key_hook(fractal->mlx_win, handle_keyboard, data);
	mlx_hook(fractal->mlx_win, 4, 0, &mouse_hook, data);
	mlx_hook(fractal->mlx_win, 6, 0, &mouse_move, data);
	mlx_hook(fractal->mlx_win, 17, 0, ft_close, data);
}
