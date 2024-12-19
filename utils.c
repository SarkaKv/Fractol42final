/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:20:19 by skvackov          #+#    #+#             */
/*   Updated: 2024/12/06 15:26:30 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	helpcheckvalidtoolong(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("not enough arg for Julia", 1);
		return (1);
	}
	if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
	{
		ft_putstr_fd("invalid number", 1);
		return (1);
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] < '0' || str[i + 1] > '9')
		{
			ft_putstr_fd("invalid number", 1);
			return (1);
		}
	}
	return (0);
}

void	my_pixel_put(t_image *image, int x, int y, int color)
{
	int	offset;

	offset = (y * image->line_len) + (x * image->bitsperplx / 8);
	*(unsigned int *)(image->pixels_ptr + offset) = color;
}

static int	minuscheck(char *input)
{
	if (*input == '-')
	{
		return (-1);
	}
	else
		return (1);
}

double	atodbl(char *input)
{
	int		sign;
	long	before;
	double	after;
	double	pow;

	sign = minuscheck(input);
	before = 0;
	after = 0;
	pow = 1.0;
	input++;
	while (*input != '.')
	{
		before = before * 10 + (*input - '0');
		input++;
	}
	if (*input == '.')
		input++;
	while (*input)
	{
		pow = pow / 10;
		after = after + (*input - '0') * pow;
		input++;
	}
	return ((before + after) * sign);
}

int	checkvalid(char *str)
{
	int	i;
	int	one;

	i = 0;
	one = 0;
	if (helpcheckvalidtoolong(str) == 1)
		return (1);
	else
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '.' && one == 0)
		{
			one = 1;
			i++;
		}
		else
		{
			ft_putstr_fd("invalid number", 1);
			return (1);
		}
	}
	return (0);
}
