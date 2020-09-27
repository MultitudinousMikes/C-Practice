

#include <stdint.h> // for uint8_t

class Image {
  
public:
  unsigned int cols;
  unsigned int rows;
  uint8_t** pixels;
  
  
  Image();
  
  
  ~Image();
  
  
  int resize( unsigned int width,  unsigned int height, uint8_t fillcolour );
  
  
  int set_pixel( unsigned int x, unsigned int y, uint8_t colour );
  
 
  int get_pixel( unsigned int x, unsigned int y, uint8_t* colourp );
  
 
  int save( const char* filename );

 
  int load( const char* filename );
};

