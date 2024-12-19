/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:50:10 by skvackov          #+#    #+#             */
/*   Updated: 2024/12/06 13:55:15 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc == 2 || argc == 4)
	{
		if ((ft_strncmp(argv[1], "Mandelbrot", 10) == 0
				&& ft_strlen(argv[1]) == 10) || (ft_strncmp("Julia", argv[1],
					5) == 0 && ft_strlen(argv[1]) == 5))
		{
			fractol.name = argv[1];
			if (ft_strncmp("Julia", argv[1], 5) == 0)
			{
				if (checkvalid(argv[2]) == 1 || checkvalid(argv[3]) == 1)
					return (1);
				else
				{
					fractol.julia_real = atodbl(argv[2]);
					fractol.julia_imag = atodbl(argv[3]);
				}
			}
			fractal_init(&fractol);
		}
	}
	else
		return (1);
}
