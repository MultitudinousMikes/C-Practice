

typedef struct element
{
  int val;
  struct element* next;
} element_t;


typedef struct list
{
  element_t* head;
  element_t* tail;
} list_t;


list_t* list_create( void );


void list_destroy( list_t* list );


element_t* element_create( int i );


int list_append( list_t* list, int i );


int list_prepend( list_t* list, int i );


element_t* list_index( list_t* list, unsigned int i );


void list_print( list_t* list );
