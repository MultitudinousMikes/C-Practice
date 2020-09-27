#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <math.h>
#include "intarr.h" 


int intarr_save_binary( intarr_t* ia, const char* filename ){
    if(ia!=NULL)
    {
	if(filename!=NULL){
    	    FILE* f = fopen(filename, "w" );
    	    fwrite( ia->data, sizeof(int), ia->len, f);
    	    fclose(f);
    	    if(intarr_load_binary(filename)!=NULL)
    	    {
	        return 0;
    	    }
	}	
    }
    return 1;
}

intarr_t* intarr_load_binary( const char* filename ){
    if(filename==NULL)
    {
	return NULL;
    }
    FILE* f = fopen(filename, "r" );
    if(f==NULL)
    {
	return NULL;
    }
    fseek(f,0,SEEK_END);
    const int k = ftell(f);
    fseek(f,0,SEEK_SET);
    const int n = ftell(f);
    int len = round((k-n)/sizeof(int));
    intarr_t *new = malloc(sizeof(intarr_t));
    new->len=len;
    new->data = malloc(len*sizeof(int));
    fread(new->data,sizeof(int),len,f);
    fclose(f);
    if(new==NULL)
    {
	return NULL;
    }
    return new;
}
