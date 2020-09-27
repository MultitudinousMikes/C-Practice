#include <stdint.h>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "image2.hpp"

Image::Image(){
	cols=0;
	rows=0;
	pixels=NULL;
}

Image::~Image(){
	delete pixels;
}

int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolour ){
	pixels=new uint8_t [width*height];	
	int i=0;
	while(i<width*height){
		pixels[i]=fillcolour;
		i++;
	}
	if(pixels==NULL){
		return 1;
	}
	return 0;
}

int Image::set_pixel( unsigned int x, unsigned int y, uint8_t colour ){
	if(x<cols && y<rows){
		pixels[y*cols+x]=colour;
		return 0;
	}
	return 1;
}
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colourp ){
	if(x<cols && y<rows){
		*colourp=pixels[y*cols+x];
		return 0;
	}
	return 1;
}

int Image::save( const char* filename ){
	if(filename==NULL){
		return 1;
	}
	FILE*f=fopen(filename, "w" );
	fwrite(pixels,sizeof(uint8_t),cols*rows,f);
	fclose(f);
	return 0;
}

int Image::load( const char* filename ){
	if(filename==NULL)
    	{
		return 1;
    	}
    	FILE* f = fopen(filename, "r" );
    	if(f==NULL)
    	{
		return 1;
    	}
    	fseek(f,0,SEEK_END);
    	const int k = ftell(f);
    	fseek(f,0,SEEK_SET);
    	const int n = ftell(f);
    	int len = (k-n)/sizeof(uint8_t);
    	pixels = new uint8_t[len];
    	fread(pixels,sizeof(uint8_t),len,f);
    	fclose(f);
    	if(pixels==NULL)
    	{	
		return 1;
    	}
    	return 0;
}

