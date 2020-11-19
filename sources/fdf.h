/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkivipur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:55:57 by mkivipur          #+#    #+#             */
/*   Updated: 2020/02/17 09:45:04 by mkivipur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>

# define ABS(value) ((value < 0) ? (value * - 1) : value)

typedef	struct		s_list
{
	int				y;
	int				x;
	int				org_x;
	int				org_y;
	int				scale_x;
	int				scale_y;
	int				height;
	int				reverse;
	int				two_d;
	int				one_time;
	int				max_x;
	int				max_y;
	int				max_negative;
	void			*win;
	void			*mlx;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				m_width;
	int				m_height;
	int				zoom;
	int				org_max;
	int				color;
	struct s_list	*next;
}					t_list;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

int					get_next_line(const int fd, char **line);
int					read_file(const int fd, void *mlx_ptr, int x, int y);
t_list				*ft_create_elem(char *coordinates, int y, int i);
void				create_linked_list(char *coordinates,
		t_list **begin_list, int y, int i);
void				list_reverse(t_list **begin_list);
void				draw(t_list coord, t_list coord_next, t_list **list);
void				move_coor_hor(t_list **begin_list);
int					count_rows(t_list **begin_list);
int					count_lines(t_list **begin_list);
void				iso(int *x, int *y, int z);
void				move_coor_ver(t_list **begin_list);
int					error_check(t_list **begin_list);
void				error_message(void);
void				error_message2(void);
void				error_message3(void);
void				error_message4(void);
int					color(t_list c_coordi, t_list c_coordi_next);
void				move_points_hor(t_list **c_coordi, t_list **c_coordi_next);
void				move_points_ver(t_list **begin_list,
		t_list **c_coordi, int rows);
void				move_points_ver2(t_list **c_coordi_next,
		int move);
void				adjust_data(t_list **begin_list,
		int max_negative, int max_x, int max_y);
void				find_max_values(t_list **begin_list);
void				get_delta_sign_val(t_list *c_coordi, t_list *c_coordi_next,
		t_point *delta, t_point *sign);
void				adjust_data_2d(t_list **begin_list);
void				adjust_data3(t_list **begin_list);
void				move_and_draw_coor(t_list **begin_list);
void				move_list_one(t_list **c_coordi, t_list **c_coordi_next);
void				init(t_list *list, void *mlx_ptr, void *win_ptr);
int					keypressed(int keycode, t_list *map);
void				reverse(t_list **begin_list, int reverse, int two_d);
void				free_array(char **coordinates);
void				adjust_point(t_point *delta, t_point *sign,
		t_list *c_coord, int *error);
void				readjust_point(t_point *delta, t_point *sign,
		t_list *c_coord, int *error);
void				two_d_display(t_list **list);
void				move_left(t_list **list);
void				move_right(t_list **list);
void				move_up(t_list **list);
void				move_down(t_list **list);
void				zoom_in(t_list **list);
void				zoom_out(t_list **list);
void				height_up(t_list **list);
void				height_down(t_list **list);
char				*get_color(char *color, char *coordinates);
int					ft_atoi_base(const char *str, int base);
int					coordinates_check(char *coordinates);
int					color_check(char *color);
void				check_max_values(t_list *tmp, int *max_x, int *max_y);
void				check_scale_values(int *scale_x, int *scale_y);
int					ft_isdigit_base(char c, int base);
void				check_map(t_list *map);
void				check_map2(t_list *map);
void				draw_background(t_list **list);
void				put_pixel(t_list *list, int x, int y, int color);

#endif
