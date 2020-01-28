void draw_line2(c_list **begin_list, void *mlx_ptr, void *win_ptr)
{


    int dx, dy, x, y;
    int step;
    int i;
    int x0;
    int x1;
    int y0;
    int y1;

    int scale;

    scale = 50;
    c_list *c_coordi;


    c_coordi = *begin_list;


  while ((c_coordi) && (c_coordi->next != NULL))
  {
    x0 = c_coordi->x;
    y0 = c_coordi->y;
    while ((c_coordi->y < scale) && (c_coordi->next != NULL))
    c_coordi = c_coordi->next;


    x1 = c_coordi->x;
    y1 = c_coordi->y;
    scale = (scale + 50);

    dx=abs(x1-x0);
	dy=abs(y1-y0);

	if(dx>=dy)
		step=dx;
	else
		step=dy;
	dx=dx/step;
	dy=dy/step;
	x=x0;
	y=y0;

	i=1;
	while(i<=step)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0000ff);
		x=x+dx;
		y=y+dy;
		i=i+1;
	}

  }

}
