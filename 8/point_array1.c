#include "point_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

void point_array_init( point_array_t* pa ){
	pa->len=0;
	pa->points=NULL;	
	pa->reserved=0;
}

void point_array_reset( point_array_t* pa ){
	int i=0;	
	while(i<pa->len){
		pa->points[i].x=0;
		pa->points[i].y=0;
		pa->points[i].z=0;
		i++;
	}
	pa->len=0;
	pa->reserved=0;
	free(pa->points);
}

int point_array_append( point_array_t* pa, point_t* p ){
	pa->len=pa->len+1;
	pa->points=realloc(pa->points,pa->len*sizeof(point_t));
	pa->points[pa->len-1].x=p->x;
	pa->points[pa->len-1].y=p->y;
	pa->points[pa->len-1].z=p->z;
	if(pa->points==NULL){
		return 1;
	}
	return 0;
}
	
int point_array_remove( point_array_t* pa, unsigned int i ){
	if(i>=pa->len || i<0){
		return 1;
	}
	pa->points[i].x=pa->points[pa->len-1].x;
	pa->points[i].y=pa->points[pa->len-1].y;
	pa->points[i].z=pa->points[pa->len-1].z;
	pa->len=pa->len-1;
	pa->points=realloc(pa->points,pa->len*sizeof(point_t));

	
	return 0;
}

