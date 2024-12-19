/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:45:21 by skvackov          #+#    #+#             */
/*   Updated: 2024/12/06 15:32:07 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

// colours
# define COLOR_BLACK 0x000000  // Black@
# define COLOR_WHITE 0xFFFFFF  // White
# define LIGHT_YELLOW 0xFFFFE0 // Yellow
# define ORANGE 0xFFA500       // Orange
# define RED 0xFF0000          // Red
# define CYAN 0x00FFFF
# define PINK 0xFFC0CB       // Pink
# define LIGHT_PINK 0xFFB6C1 // Light Pink
# define HOT_PINK 0xFF69B4   // Hot Pink
# define TURQUOISE 0x40E0D0

// keys
# define KEY_ESC 65307   // Escape key
# define KEY_UP 65362    // Up arrow
# define KEY_DOWN 65364  // Down arrow
# define KEY_LEFT 65361  // Left arrow
# define KEY_RIGHT 65363 // Right arrow
# define KEY_W 119       // W key
# define KEY_A 97        // A key
# define KEY_S 115       // S key
# define KEY_D 100       // D key

// mouse
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_image
{
	void		*mlx_image_ptr;
	char		*pixels_ptr;
	int			bitsperplx;
	int			endian;
	int			line_len;
}				t_image;

typedef struct s_complexnumber
{
	double		x;
	double		y;
}				t_complexnumber;

typedef struct s_fractol
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_image		image;
	double		escape_value;
	int			iteration;
	double		shift_x;
	double		shift_y;
	double		julia_real;
	double		julia_imag;
	double		zoom;
	int			colour_shift;
}				t_fractol;

void			fractal_init(t_fractol *fractol);
double			scaling(double x, double startpoint2, double endpointpoint2,
					t_fractol *fractol);
void			fractal_render(t_fractol *fractol);
double			forcolours(double x, double startpoint2, double endpointpoint2);
void			my_pixel_put(t_image *image, int x, int y, int color);
void			data_init(t_fractol *fractol);
t_complexnumber	addition(t_complexnumber one, t_complexnumber two);
t_complexnumber	squarecomplex(t_complexnumber z);
int				close_handling(t_fractol *fractol);
int				key_handler(int keysym, t_fractol *fractol);
void			events(t_fractol *fractol);
int				mouse_handling(int button, int x, int y, t_fractol *fractol);
double			atodbl(char *input);
int				checkvalid(char *str);
int				motion_handling(int x, int y, t_fractol *fractol);

#endif
