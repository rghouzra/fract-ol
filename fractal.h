/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:11:17 by rghouzra          #+#    #+#             */
/*   Updated: 2022/11/22 11:26:40 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# define BLUE_GOLD 0x00339Cff
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define BLACK 0x000000
# define YELLOW 0X00E4EE13
# define TRANSPARENCY 0x66000000

typedef struct s_list
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		option;
}t_list;

typedef struct s_julia
{
	double	rl;
	double	img;
	int		move;
}t_julia;

typedef struct s_data
{
	int		x;
	int		y;
	int		width;
	int		height;
	double	xcenter;
	double	ycenter;
	double	w;
	double	h;
	double	scale;
	int		(*fractol)(struct s_data *);
	int		iteration;
	int		max_iteration;
	void	*img;
	int		xmouse;
	int		ymouse;
	int		color;
	t_julia	*julia_ptr;
	t_list	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;
typedef struct s_complex
{
	double	a;
	double	b;
}t_complex;
int			scnd_keyboard_handlera(int code, t_data *env);
char		*title_win(int option);
int			mouse_move(int x, int y, void *data);
void		ft_draw(t_data *data, int (*function)(t_data *data));
int			ft_strlen(char *s);
int			ft_color(t_data *d);
int			perpe_burning_ship(t_data *data);
int			ft_close(t_data *param);
int			mouse_hook(int keycode, int x, int y, void *data);
t_complex	ft_map(t_data *data);
int			handle_keyboard(int code, t_data *env);
void		ft_hook_event(t_list *fractal, t_data *data);
void		ft_putstr(char *s, int fd);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			julia(t_data *data);
void		exit_with_print(char *s);
void		ft_init(t_data *data);
int			mandelbrot(t_data *data);
#endif
