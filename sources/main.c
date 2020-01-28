    #include "fdf.h"
    #include "mlx.h" 

   int  count_rows(c_list **begin_list)
   {
       c_list *c_coordi;
       c_list  *tmp;
       int  count;

       count = 1;
       c_coordi = *begin_list;

       while ((c_coordi) && (c_coordi->next != NULL))
        {
           tmp = c_coordi->next;
            if (c_coordi->y == tmp->y)
            {
                if ((c_coordi->x != tmp->x) && (c_coordi->y == tmp->y))
                count++;
                c_coordi = tmp;
            }
            else 
            return (count);
        }
    
    return (count);
    }

   int count_lines(c_list **begin_list)
   {
       c_list *c_coordi;
       c_list  *tmp;
       int  count;

       count = 1;
       c_coordi = *begin_list;

       while (c_coordi)
        {
            if (c_coordi->next != NULL)
            {
                tmp = c_coordi->next;
                if (c_coordi->y != tmp->y)
                count++;
                c_coordi = tmp;
            }
            else
            break;
        }
    return (count);
   }
   

   
   void draw_horizontal(c_list **begin_list, void *mlx_ptr, void *win_ptr)
{
    
    
    int dx, dy, x, y;
    int step;
    int i;
    

    c_list *c_coordi;
    c_list *c_coordi_next;
    
    c_coordi = *begin_list;
    c_coordi_next = c_coordi->next;    

 while ((c_coordi) && (c_coordi->next != NULL))
  {
    
if ((c_coordi->y) != (c_coordi_next->y))
      {
          c_coordi = c_coordi_next;
          c_coordi_next = c_coordi->next;
      }
    dx=abs(c_coordi_next->x - c_coordi->x);
	dy=abs(c_coordi_next->y - c_coordi->y);
 
	
	step=dx;
	dx=dx/step;
	dy=dy/step;
	x=c_coordi->x;
	y=c_coordi->y;
 
	i=1;
	while(i<=step)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0000ff);
		x=x+dx;
		y=y+dy;
		i=i+1;
	}
    c_coordi = c_coordi_next;
    c_coordi_next = c_coordi->next;
  }
	
}

void draw_vertical(c_list **begin_list, void *mlx_ptr, void *win_ptr)
{
    
    int dx, dy, x, y;
    int step;
    int i;
    int lines;
    int rows;
    c_list *c_coordi;
    
    c_coordi = *begin_list;
    lines = count_lines(begin_list);
    rows = count_rows(begin_list);
    x = 150;
    y = 0;
    

while (0 < rows) 
{
while (((c_coordi) && (c_coordi->next != NULL)) && (y < ((7 * 25 + (lines * 25)))))
  {
    y = c_coordi->y;
    while (((c_coordi->y == y) || (c_coordi->x != x)) && (c_coordi->next != NULL))
    c_coordi = c_coordi->next;
    dx=0;
	dy=abs(c_coordi->y - y);
    step=dy;
    dy=dy/step;
    i=1;
	while(i<=step)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0000ff);
		x=x+dx;
		y=y+dy;
		i=i+1;
       
	}
    
  }
  rows--;
  x = (x + 25);
  y = 0;
  c_coordi = *begin_list;
}
	
}



int		read_file(const int fd, void *mlx_ptr, void *win_ptr)
{
       char *line;
        char **coordinates;
        int y;
        int x;
        int lines;
        int rows;
      c_list *begin_list;
        
        lines = 0;
        rows = 0;
        y = 0;
        begin_list = NULL;
        while ((x = get_next_line(fd, &line)) == 1)
         {  
             x = 0;
            coordinates = ft_strsplit(line, ' ');
            while (coordinates[x] != NULL)
            {
            create_linked_list(coordinates[x], &begin_list, y, x);
            x++;
            }
            y++;
            free(coordinates);
         }
         draw_vertical(&begin_list, mlx_ptr, win_ptr);
         draw_horizontal(&begin_list, mlx_ptr, win_ptr);
        return (1);
}
    
    int		main(int argc, char **argv)
{
	void *mlx_ptr;
    void *win_ptr;
  
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 750, 750, "mlx 42");
    
	int		fd;

	if (argc < 2)
	{ 
    ft_putstr("Not enough arguments");
    return (0);  
    }
    fd = open(argv[1], O_RDONLY);
	
    read_file(fd, mlx_ptr, win_ptr);

    
mlx_loop(mlx_ptr);
return (0);
}
