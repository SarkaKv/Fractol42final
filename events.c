/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-16 08:49:54 by skvackov          #+#    #+#             */
/*   Updated: 2024-12-16 08:49:54 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "fractol.h"

void	events(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, KeyPress, KeyPressMask, key_handler, fractol);
	mlx_hook(fractol->mlx_window, ButtonPress, ButtonPressMask, mouse_handling,
		fractol);
	mlx_hook(fractol->mlx_window, MotionNotify, PointerMotionMask,
		motion_handling, fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handling, fractol);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == KEY_LEFT)
	{
		fractol->shift_x -= 0.07 * (fractol->zoom * 4);
	}
	if (keysym == KEY_RIGHT)
		fractol->shift_x += 0.07 * (fractol->zoom * 4);
	if (keysym == KEY_UP)
	{
		fractol->shift_y -= 0.07 * (fractol->zoom * 4);
	}
	if (keysym == KEY_DOWN)
	{
		fractol->shift_y += 0.07 * (fractol->zoom * 4);
	}
	if (keysym == KEY_ESC)
	{
		close_handling(fractol);
	}
	fractal_render(fractol);
	return (0);
}

int	mouse_handling(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
		fractol->zoom *= 0.8;
	if (button == MOUSE_SCROLL_DOWN)
		fractol->zoom *= 1.1;
	fractal_render(fractol);
	return (0);
}

int	motion_handling(int x, int y, t_fractol *fractol)
{
	fractol->colour_shift = (x + y) % 256;
	if (fractol->colour_shift % 5 == 1 && fractol->colour_shift % 3 == 1
		&& fractol->colour_shift % 2 == 2)
		fractal_render(fractol);
	return (0);
}

int	close_handling(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->image.mlx_image_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(0);
}
