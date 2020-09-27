#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void draw_rectangle( uint8_t array[], 
		          unsigned int cols, 
		          unsigned int rows, 
		          int x,
		          int y,
		          int rect_width,
		          int rect_height,
		          uint8_t color )
{
    if(rect_width>0 && rect_height >0)
    {
        for(int i = x; i<x+rect_width; i++)
        {
	    int j=y;
            while(j < y+rect_height)
            {
        	if(i<cols && j<rows)
		{        
		    if(i==x || i == x+rect_width-1)
                    {
                    	set_pixel(array, cols, rows, i,j,color);
                    }
                    if(j == y || j == y+rect_height -1)
                    {
                        set_pixel(array, cols, rows, i,j,color);
                    }
		}
		j++;
            }
        }
    }
    else if(rect_width<0 && rect_height>0)
    {
        for(int i = x; i> x+rect_width; i--)
        {
	    int j=y;
            while(j < y+rect_height)
            {
                if(i<cols && j<rows)
		{ 
			if(i==x || i == x+rect_width+1)
                	{
                    		set_pixel(array, cols, rows, i,j,color);
                	}
                	if(j == y || j == y+rect_height -1)
                	{
                    		set_pixel(array, cols, rows, i,j,color);
                	}
		}
		j++;
            }
        }
    }
    else if(rect_width>0 && rect_height<0)
    {
        for(int i = x; i< x+rect_width; i++)
        {
	    int j=y;
            while(j>y+rect_height)
            {
		if(i<cols && j<rows)
		{                 
			if(i==x || i == x+rect_width-1)
                	{
                    		set_pixel(array, cols, rows, i,j,color);
                	}	
                	if(j == y || j == y+rect_height +1)
                	{
                		set_pixel(array, cols, rows, i,j,color);
                	}
		}
		j--; 
            }
        }   
    }
    else if(rect_width<0 && rect_height<0)
    {
        for(int i = x; i> x+rect_width; i--)
        {
	    int j=y;
            while(j>y+rect_height)
            {
		if(i<cols && j<rows)
		{ 
                	if(i==x || i == x+rect_width+1)
                	{
                    		set_pixel(array, cols, rows, i,j,color);
                	}
                	if(j == y || j == y+rect_height +1)
                	{
                    		set_pixel(array, cols, rows, i,j,color);
                	}
		}
		j--;
            }
        }
    }
}

