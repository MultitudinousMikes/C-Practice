#include <stdint.h>
#include <stdlib.h>
#include "imgops.h"

unsigned int hoodsize(uint8_t array[],
		unsigned int cols,
		unsigned int rows,
		unsigned int p,
		unsigned int q)
{
	unsigned int sum=0;
	for(int x=-1;x<=1;x++)
	{
		for(int y=-1;y<=1;y++)
		{
			if(!(x==0&&y==0))
			{
				int xx = (p+x+cols)%cols;
				int yy = (q+y+rows)%rows;
				sum += get_pixel(array,cols,rows,xx,yy)>0;
			}
		}
	}
	return sum;
}

void life(uint8_t array[],
	unsigned int cols,
	unsigned int rows)
{
	uint8_t *cp = copy(array,cols,rows);
	for(int x=0;x<cols;x++)
	{	
		for(int y=0;y<rows;y++)
		{
			unsigned int hood = hoodsize(cp,cols,rows,x,y);
			if(hood<2)
			{
				set_pixel(array,cols,rows,x,y,0);
			}
			if(hood>3)
			{
				set_pixel(array,cols,rows,x,y,0);
			}
			if(hood==3)
			{
				set_pixel(array,cols,rows,x,y,255);
			}
		}
	}
	free(cp);
}

		
	
