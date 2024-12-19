/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:24:06 by skvackov          #+#    #+#             */
/*   Updated: 2024/12/06 15:34:06 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scaling(double x, double start2, double end2, t_fractol *fractol)
{
	double	results;
	double	startpoint1;
	double	endpoint1;

	startpoint1 = -2.0;
	endpoint1 = 2.0;
	results = startpoint1 + ((x - start2) / (end2 - start2) * (endpoint1
				- startpoint1));
	return (results * fractol->zoom);
}

double	forcolours(double x, double startpoint2, double endpointpoint2)
{
	double	results;
	double	startpoint1;
	double	endpoint1;

	startpoint1 = LIGHT_YELLOW;
	endpoint1 = HOT_PINK;
	results = startpoint1 + ((x - startpoint2) / (endpointpoint2 - startpoint2)
			* (endpoint1 - startpoint1));
	return (results);
}

t_complexnumber	addition(t_complexnumber one, t_complexnumber two)
{
	t_complexnumber	result;

	result.x = one.x + two.x;
	result.y = one.y + two.y;
	return (result);
}

t_complexnumber	squarecomplex(t_complexnumber z)
{
	t_complexnumber	results;

	results.x = (z.x * z.x) - (z.y * z.y);
	results.y = 2 * z.x * z.y;
	return (results);
}
