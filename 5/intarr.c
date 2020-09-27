#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <math.h>


typedef struct {
  int* data;
  unsigned int len;
} intarr_t;

typedef enum {
  INTARR_OK,
  INTARR_BADARRAY,
  INTARR_BADINDEX,
  INTARR_BADALLOC,
  INTARR_NOTFOUND
} intarr_result_t;

intarr_t* intarr_create( unsigned int len )
{
    intarr_t *new = malloc(sizeof(intarr_t));
    new->data=malloc(len*sizeof(int));
    new->len = len;
    if((new)!=NULL)
    {
        return new;
    }
    else{
        return NULL;
    }
}

void intarr_destroy( intarr_t* ia )
{
    if(ia!=NULL)
    {
    	if(ia->data!=NULL)
    	{
            free(ia);
    	}
    	else{
	        return;
    	}
    }
}

intarr_result_t intarr_set( intarr_t* ia, 
			    unsigned int index, 
			    int val )
{
    if(ia==NULL)
    {
        return INTARR_BADARRAY;
    }
    if(index>=0 && index<ia->len)
    {
	    ia->data[index]=val;        
	    return INTARR_OK;
    }
    else
    {
        return INTARR_BADINDEX;
    }
}

intarr_result_t intarr_get( const intarr_t* ia, 
			    unsigned int index, 
			    int* i )
{
    if(ia==NULL)
    {
        return INTARR_BADARRAY;
    }
    if(index>=0 && index<ia->len && i!=NULL)
    {
        *i=ia->data[index];
        return INTARR_OK;
    }
    return INTARR_BADINDEX;
}

intarr_t* intarr_copy( const intarr_t* ia )
{

    int i=ia->len;
    unsigned int u=i*sizeof(int);
    intarr_t *duplicate = malloc(sizeof(const intarr_t));
    duplicate->data=malloc(i*sizeof(int));
    duplicate->len=ia->len; 
    memcpy( duplicate->data, ia->data, u);
    if(duplicate == NULL)
    {
        return NULL;
    }
    return duplicate;
}

intarr_result_t intarr_sort( intarr_t* ia ){
    if(ia==NULL)
    {
	return INTARR_BADARRAY;
    }
    for (int x=0;x<ia->len;x++)
    {
        for(int j=ia->len;j>x;j--)
        {
            if (ia->data[j]<ia->data[j-1])
            {
                int k = ia->data[j];
                ia->data[j] = ia->data[j-1];
                ia->data[j-1]=k;
            }
        }
    }
    return INTARR_OK;
}


intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){
    if(ia==NULL)
    {
	    return INTARR_BADARRAY;
    }
    for (int x=0;x<ia->len;x++)
    {
	if(ia->data[x]==target && i!=NULL)
	{
	    *i=x;
	    return INTARR_OK;
	}
    }
	return INTARR_NOTFOUND;
}



intarr_result_t intarr_push( intarr_t* ia, int val ){
    if(ia==NULL)
    {
	return INTARR_BADARRAY;
    }
    int i = ia->len+1;
    ia->data=realloc(ia->data,i*sizeof(int));
    ia->len=i;
    if(ia->data!=NULL)
    {
	ia->data[i-1]=val;
	return INTARR_OK;
    }
    else{
	return INTARR_BADALLOC;
    }
}


intarr_result_t intarr_pop( intarr_t* ia, int* i ){
    if(ia==NULL)
    {
	return INTARR_BADARRAY;
    }
    if(ia->data==NULL)
    {
	return INTARR_BADINDEX;
    }
    if(i!=NULL)
    {
    	*i = ia->data[ia->len-1];
    	int x = ia->len-1;
    	ia->data=realloc(ia->data,x*sizeof(int));
    	ia->len=x;
   	return INTARR_OK;
    }
}


intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
    if (ia==NULL)
    {
	return INTARR_BADARRAY;
    }
    intarr_t* new=ia;
    int i = ia->len;
    ia->data = malloc(newlen * sizeof(int));
    ia->len=newlen;
    if(i<=newlen)
    {
        for (int x=0; x<i; x++)
        {
            ia->data[x]= new->data[x];
        }
    }
    else
    {
        ia->data = new->data;
        for (int x = i;i<newlen; x++)
        {
            ia->data[x]=0;
        }
    }
    if(ia==NULL)
    {
	return INTARR_BADALLOC;
    }
    return INTARR_OK;
}


intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last ){
    
    if(ia!=NULL)
    {
	if(first<=last)
	{
	    if(first>=0 && last<ia->len)
	    {
		int a=last-first+1;
		intarr_t *new = malloc(sizeof(intarr_t));
		new->data = malloc(a*sizeof(int));
		new->len = a;
		int x=0;
		int j=first;
		while (j<=last)
		{
		    new->data[x]=ia->data[j];
		    x++;
		    j++;
		}
		intarr_t *du = malloc(sizeof(intarr_t));
		du->data = malloc(a*sizeof(int));
		du->len=a;
		memcpy(du->data,new->data,a*sizeof(int));
		return du;
	    }
	}
    }
    return NULL;
}



