#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void draw_circle( uint8_t img[], 
                  unsigned int cols,
                  unsigned int rows,
		  int x,
		  int y,
		  int r,
		  uint8_t color )
{
	if(r<1)
	{
	    return;
	}
	for (int i=0; i<cols; i++)
	{
	   for (int j=0; j<rows; j++)
	   {
	       const float X = abs(x-i)-0.5;
	       const float Y = abs(y-j)-0.5;
	       const float dis = sqrt(pow(X,2)+pow(Y,2));
	       if(dis<r)
	       {
	           img[j*cols + i] = color;
	       }
	   }
	}
}
