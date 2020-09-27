#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main( int argc, char* argv[] )
{
  // test the create function
  list_t* list = list_create();

  // check to see if the create function did everything it was supposed to
  if( list == NULL )
    {
      printf( "create: create failed to malloc\n" );
      return 1;
    }

  if( list->head != NULL )
    {
      printf( "create: head is not null!\n" );
      return 1;
    }

  if( list->tail != NULL )
    {
      printf( "create: tail is not null!\n" );
      return 1;
    }

  // now test all the other functions (except list_print) to see if
  // they do what they are supposed to
  int i=1;
  list_t* lt1 = list_create();
  list_t* lt2 = list_create();
  list_t* lt3 = list_create();
  list_t* lt4 = list_create();
  list_t* lt5 = list_create();
  element_t*new1 = list_index(lt1,1);//t1
  if(new1!=NULL){
	return 1;
  }
  list_destroy(lt1);
  element_t*new2 = element_create(1);//t2
  new2->next=5;
  free(new2);
  new2=NULL;
  new2 = element_create(1);
  if(new2==NULL){
	return 1;
  }
  if(new2->val==1 && new2->next!=NULL){
	return 1;
  }
  list_destroy(lt2);
  element_t*new4 = list_index(lt3,0);//t3
  list_destroy(lt3);
  list_prepend(lt4,i);
  if(lt4->tail==NULL){
	   return 1;
  }
  list_destroy(lt4);

  list_append(lt5,1);
  list_append(lt5,2);

  element_t*new5 = list_index(lt5,3);
  if(new5!=NULL){
	return 1;
  }
  
  list_destroy(lt5);
  
  
  list_destroy(list);
  return 0; // tests pass
}
