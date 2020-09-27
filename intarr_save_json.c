#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>



int intarr_save_json( intarr_t* ia, const char* filename ){
    if(ia!=NULL && ia->data!=NULL){
    	if(filename!=NULL){
    	    FILE *a=fopen(filename, "w+");
    	    fprintf(a,"[");
    	    for(int i=0; i<ia->len;i++){
		fprintf(a,"%d",ia->data[i]);
		if(i!=ia->len-1){
		    fprintf(a,",");
		}
	    }
    	    fprintf(a,"]");
            fclose(a);
	    if(intarr_load_json(filename)!=NULL){
		return 0;
	    }
        }
    }
    return 1;
}



intarr_t* intarr_load_json( const char* filename ){
    if(filename==NULL)
    {
	return NULL;
    }
    FILE *a = fopen(filename, "r+");
    if(a==NULL)
    {
	return NULL;
    }
    int x=0;
    int p;
    char st;
    while(!feof(a))
    {
	st=getc(a);
	if(st==','){
	    x++;
	}
    }
    fseek(a,0,SEEK_SET);
    intarr_t *new = malloc(sizeof(intarr_t));
    if(x==0){
	new->len=0;
	new->data=NULL;
	return new;
    }
    new->len = x+1;
    new->data = malloc(new->len*sizeof(int));
    for (int j=0;j<new->len;j++)
    {
	while(fscanf(a,"%d",&p)!=1){
	    fseek(a,1,SEEK_CUR);
	}
	new->data[j]=p;
    }
    fclose(a);
    if(new==NULL){
	return NULL;
    }
    return new;
	    
}


