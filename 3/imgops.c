

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}


void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 


void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
	for(unsigned int x=0; x<cols;x++)
	{
		for(unsigned int y=0; y<rows;y++)
		{
			set_pixel(array,cols,rows,x,y,0);
		}
	}
  
}


uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{

  return NULL;
}




uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
	int min=225;
	for (unsigned int i =0; i<(cols*rows);i++)
	{
		if (array[i]<=min)
		{
			min = array[i];
		}
	}
  	return min;
}


uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
	int max=0;
	for (unsigned int i =0; i<(cols*rows);i++)
	{
		if (array[i]>=max)
		{
			max = array[i];
		}
	}  
  	return max;
}


void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
	for(unsigned int x = 0; x<cols;x++)
	{
		for (unsigned int y=0;y<rows;y++)
		{
			if(get_pixel(array,cols,rows,x,y)==pre_color)
			{
				set_pixel(array,cols,rows,x,y,post_color);
			}
		}
	}
}


void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
	for(unsigned int x = 0; x<cols/2;x++)
	{
		for (unsigned int y=0;y<rows;y++)
		{
			uint8_t a = get_pixel(array,cols,rows,x,y);
			uint8_t b = get_pixel(array,cols,rows,cols-x-1,y);
			set_pixel(array,cols,rows,cols-x-1,y,a);
			set_pixel(array,cols,rows,x,y,b);
		}
	}
}


void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
	for(unsigned int x = 0; x<cols;x++)
	{
		for (unsigned int y=0;y<rows/2;y++)
		{
			uint8_t a = get_pixel(array,cols,rows,x,y);
			uint8_t b = get_pixel(array,cols,rows,x,rows-y-1);
			set_pixel(array,cols,rows,x,rows-y-1,a);
			set_pixel(array,cols,rows,x,y,b);
		}
	}
}


int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
	for(int j=0;j<rows;j++)
	{
		for(int i =0; i<cols;i++)
		{
			if ((get_pixel(array,cols,rows,i,j)) == color)
			{
				*x=i;
				*y=j;
				return 1;
			}
		}
	}
    	return 0;
}



void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
	for (unsigned int i=0;i<(rows*cols);i++)
	{
		array[i]=255-array[i];
	}
}


void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
	for(int i=0; i<(rows*cols);i++)
	{
		if(array[i]*scale_factor>255.0)
		{
			array[i]=255;
		}
		else
		{
			array[i]=round(array[i]*scale_factor);
		}
	}
}



void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
    	uint32_t a = min(array,cols,rows);
	uint32_t b = max(array,cols,rows);
	uint32_t range = b-a;
	for (uint32_t i=0;i<(rows*cols);i++)
	{
		array[i]=round((array[i]-a)*(255.0/(b-a)));

	}
}

           
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
	uint8_t* new = malloc(sizeof(uint8_t)*((rows)/2)*((cols)/2));
    	if(new!=NULL)
	{
      		for (uint8_t y=0;y<rows/2;y++)
        	{
            		for (uint8_t x=0;x<cols/2;x++)
            		{	
              			uint8_t a = get_pixel(array, cols,rows,2*x,2*y);
              			uint8_t b = get_pixel(array, cols,rows,2*x+1,2*y);
              			uint8_t c = get_pixel(array, cols,rows,2*x,2*y+1);
              			uint8_t d = get_pixel(array, cols,rows,2*x+1,2*y+1);
              			uint8_t k = round((a+b+c+d)/4.0);
              			set_pixel(new,cols/2,rows/2,x,y,k);
            		}
        	}
      	}
      	return new;
}






void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
	if((top!=bottom)&&(right!= left))
	{
		for(unsigned  int x=left;x<right;x++)
		{
			for(unsigned int y=top; y<bottom;y++)
			{
 				set_pixel(array,cols,rows,x,y,color);
			}
		}
	}

}


unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
    
    return 0;
}


uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
	unsigned int x = right-left;
  	unsigned int y = bottom-top;
  	if ((left == right) || (top == bottom))
  	{
    		return NULL;
  	}
    	else  
    	{
      		uint8_t* new = malloc((x)*(y)*sizeof(uint8_t));
      		if (new == NULL)
      		{
        		return NULL;
      		}
		else
		{      	
			for (unsigned int j=top;j<bottom;j++)
      			{
          			for (unsigned int i=left;i<right;i++)
          			{
              				uint8_t k = get_pixel(array, cols, rows,i,j);
              				set_pixel(new,x,y,i-left,j-top,k);
          			}
      			}
		}
      		return new;
	}    
} 



