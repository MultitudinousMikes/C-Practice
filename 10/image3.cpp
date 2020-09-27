#include <stdint.h>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "image3.hpp"

Image::Image(){
	cols=0;
	rows=0;
	pixels=NULL;
}

Image::~Image(){
	delete pixels;
}

int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolour ){
	pixels=new uint8_t*[width];	
	int i=0;
	while(i<width){
		pixels[i]=new uint8_t[height];
		i++;
	}
	i=0;
	int j=0;
	while(i<width){
		while(j<height){
			pixels[i][j]=fillcolour;
			j++;
		}
		i++;
	}
	if(pixels==NULL){
		return 1;
	}
	return 0;
}

int Image::set_pixel( unsigned int x, unsigned int y, uint8_t colour ){
	if(x<cols && y<rows){
		pixels[x][y]=colour;
		return 0;
	}
	return 1;
}
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colourp ){
	if(x<cols && y<rows){
		*colourp=pixels[x][y];
		return 0;
	}
	return 1;
}

int Image::save( const char* filename ){
	if(filename==NULL){
		return 1;
	}
	FILE*f=fopen(filename, "w" );
	for(int i=0;i<cols;i++){
		fwrite(pixels[i],sizeof(uint8_t),rows,f);
		fprintf(f,"\n");
	}
	fclose(f);
	return 0;
}

int Image::load( const char* filename ){
	if(filename==NULL)
    	{
		return 1;
    	}
    	FILE *a = fopen(filename, "r+");
    	if(a==NULL)
    	{
		return 1;
    	}
    	int x=0;
    	int p;
    	char st;
    	while(!feof(a))
    	{
		st=getc(a);
		if(st=='\n'){
	    	x++;
		}
    	}
	cols=x;
 	fseek(a,0,SEEK_END);
    	const int k = ftell(a);
    	fseek(a,0,SEEK_SET);
    	const int n = ftell(a);
    	int len =(k-n)/sizeof(uint8_t);
    	if(cols==0){
		rows=0;
		pixels=NULL;
		return 0;
    	}
	rows=len/cols;
	
   	pixels=new uint8_t*[cols];
	int b=0;
	while(b<cols){
		pixels[b]=new uint8_t[rows];
		b++;
	}
	fseek(a,0,SEEK_SET);
    	for (int j=0;j<cols;j++)
    	{
		for(int z=0;z<rows;z++){
			while(fscanf(a,"%d",&p)!=1){
	    			fseek(a,1,SEEK_CUR);
			}
			pixels[j][z]=p;
		}
    	}
    	fclose(a);
    	if(pixels==NULL){
		return 1;
    	}
    	return 0;
	    
}

