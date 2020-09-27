#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
void list_merge( list_t* lis1,list_t* lis2 ){
	if(lis2->head!=NULL){
		if(lis1->head!=NULL){
    			lis1->tail->next = lis2->head;
			lis1->tail= lis2->tail;
		}else{
			*lis1 = *lis2;
		}
	}
	free(lis2);
}

void list_sort( list_t* list ){
	if (list->head == list->tail) {
        	return;
    	}
    	int k = list->head->val;
	list_t *l=list_create();
	list_t *r=list_create();
	list->head=list->head->next;
    	element_t *new=list->head;
        element_t *a;
    	while (new!= NULL) {
    	    	a=new->next;
		new->next=NULL;
        	if(new->val<=k){
			list_append(l,new->val);
		}
		else if (new->val>k){
			list_append(r,new->val);
		}
		new=a;
    	}
    	list->head=NULL;
	list->tail=NULL;
    	list_sort(l);
    	list_sort(r);
    	list_merge(list, l);
    	list_append(list,k);
    	list_merge(list, r);
}
