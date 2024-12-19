/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_initialization.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:32:21 by skvackov          #+#    #+#             */
/*   Updated: 2024/12/06 15:19:51 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iteration = 70;
	fractol->zoom = 1.0;
}

static void	errorhandler_innit(t_fractol *fractol)
{
	if (fractol->image.mlx_image_ptr != NULL)
	{
		mlx_destroy_image(fractol->mlx_connection,
			fractol->image.mlx_image_ptr);
	}
	if (fractol->mlx_window != NULL)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	}
	if (fractol->mlx_connection != NULL)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
	}
	exit(1);
}

static void	linetoolongstart(t_fractol *fractol)
{
	data_init(fractol);
	events(fractol);
	fractal_render(fractol);
	mlx_loop(fractol->mlx_connection);
}

void	fractal_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
	{
		ft_putstr_fd("Failed to initilize mlx connection", 1);
		exit(1);
	}
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT,
			fractol->name);
	if (fractol->mlx_window == NULL)
		errorhandler_innit(fractol);
	fractol->image.mlx_image_ptr = mlx_new_image(fractol->mlx_connection, WIDTH,
			HEIGHT);
	if (fractol->image.mlx_image_ptr == NULL)
		errorhandler_innit(fractol);
	fractol->image.pixels_ptr = mlx_get_data_addr(fractol->image.mlx_image_ptr,
			&fractol->image.bitsperplx, &fractol->image.line_len,
			&fractol->image.endian);
	if (fractol->image.pixels_ptr == NULL)
		errorhandler_innit(fractol);
	linetoolongstart(fractol);
}
