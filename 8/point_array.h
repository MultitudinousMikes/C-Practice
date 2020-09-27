#include <stdlib.h>


typedef struct point
{
  double x, y, z;
} point_t;

typedef struct 
{
  
  size_t len;
  
  
  point_t* points;
  
  
  size_t reserved; 
  
} point_array_t;



void point_array_init( point_array_t* pa );


void point_array_reset( point_array_t* pa );


int point_array_append( point_array_t* pa, point_t* p );


int point_array_remove( point_array_t* pa, unsigned int i );


