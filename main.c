/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:03:39 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/22 19:10:44 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	second_main(char *option)
{
	if ((ft_strlen(option) == ft_strlen("julia"))
		&& !(ft_strncmp(option, "julia", ft_strlen("julia"))))
		return (1);
	else if ((ft_strlen(option) == ft_strlen("mandelbrot"))
		&& !(ft_strncmp(option, "mandelbrot", ft_strlen("mandelbrot"))))
		return (2);
	else if ((ft_strlen(option) == ft_strlen("p_burning_ship"))
		&& !(ft_strncmp(option, "p_burning_ship", ft_strlen("p_burning_ship"))))
		return (3);
	exit_with_print("Option error");
	return (0);
}

int	prepare_mlx(t_list *fractal, t_data *img)
{
	ft_init(img);
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		exit_with_print("error in init");
	fractal->mlx_win = mlx_new_window(fractal->mlx_ptr, 800, 800, \
		title_win(fractal->option));
	img->img = mlx_new_image(fractal->mlx_ptr, 800, 800);
	if (!img->img)
		exit_with_print("error in mlx_new_image");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	return (0);
}

int	which_fractal(t_list *fractal, t_data *data)
{
	if (fractal->option == 1)
	{
		data->fractol = julia;
		ft_draw(data, julia);
	}
	else if (fractal->option == 2)
	{
		data->fractol = mandelbrot;
		ft_draw(data, mandelbrot);
	}
	else if (fractal->option == 3)
	{
		data->fractol = perpe_burning_ship;
		ft_draw(data, perpe_burning_ship);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	fractal;
	t_data	*img;

	if (ac != 2)
		exit_with_print("Error usage you have to choose between:\n\t1:\
  mandelbrot\n\t2:    julia\n\t3: perpendicular burning ship\n");
	img = malloc(sizeof(t_data));
	if (!img)
		return (1);
	img->julia_ptr = malloc(sizeof(t_julia));
	if (!img->julia_ptr)
		ft_close(img);
	fractal.option = second_main(av[1]);
	prepare_mlx(&fractal, img);
	img->ptr = &fractal;
	which_fractal(&fractal, img);
	ft_hook_event(&fractal, img);
	mlx_loop(fractal.mlx_ptr);
	free(img->julia_ptr);
	free(img);
	return (0);
}
