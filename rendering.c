/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:37:49 by skvackov          #+#    #+#             */
/*   Updated: 2024/12/06 15:28:14 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixelhandlingforjulia(int x, int y, t_fractol *fractol)
{
	t_complexnumber	z;
	t_complexnumber	c;
	int				i;
	int				color;

	i = 0;
	z.x = scaling(x, 0, (double)799, fractol) + fractol->shift_x;
	z.y = scaling(y, 0, (double)799, fractol) + fractol->shift_y;
	c.x = fractol->julia_real;
	c.y = fractol->julia_imag;
	while (i < fractol->iteration)
	{
		z = addition(squarecomplex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = forcolours(i, 0, fractol->iteration);
			my_pixel_put(&fractol->image, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&fractol->image, x, y, COLOR_BLACK);
}

static void	pixelhandlingformandelbrot(int x, int y, t_fractol *fractol)
{
	t_complexnumber	z;
	t_complexnumber	c;
	int				i;
	int				color;

	i = 0;
	c.x = scaling(x, 0, (double)799, fractol) + fractol->shift_x;
	c.y = scaling(y, 0, (double)799, fractol) + fractol->shift_y;
	z.x = 0.0;
	z.y = 0.0;
	while (i < fractol->iteration)
	{
		z = addition(squarecomplex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = forcolours(i + fractol->colour_shift, 0,
					fractol->iteration);
			my_pixel_put(&fractol->image, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&fractol->image, x, y, COLOR_BLACK);
}

void	fractal_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (ft_strncmp("Julia", fractol->name, 5) == 0)
				pixelhandlingforjulia(x, y, fractol);
			if (ft_strncmp("Mandelbrot", fractol->name, 10) == 0)
				pixelhandlingformandelbrot(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
		fractol->image.mlx_image_ptr, 0, 0);
}
