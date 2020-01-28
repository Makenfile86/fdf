#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_list
{
	int				y;
	int			    x;
	int            height;
    struct s_list	*next;
}					c_list;

int	get_next_line(const int fd, char **line);
c_list	*ft_create_elem(char *coordinates, int y, int i);
void  create_linked_list(char *coordinates, c_list **begin_list, int y, int i);

#endif