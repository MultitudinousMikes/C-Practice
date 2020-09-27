#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int i=0;
    int x, y, z;
    scanf ("%d", &x);    
    scanf ("%d", &y);
    scanf ("%d", &z);
    if(x==1 && y==1 && z==1){
        printf("#");
        printf("\n");
        return 0;
    }
    int left = floor( (z-1) * (x/(2.0*z)) );
    int right = ceil( (x-1) + -(z-1) * (x/(2.0*z)) );
    for(int k = 0; k<left;k++)
    {
        printf(" ");
    }
    for(int o=left;o<=right;o++){
        printf("#");
    }
    printf("\n");
    for(int p = z-2; p>=1; p--)
    {
        int left = floor( p * (x/(2.0*z)) );
        int right = ceil( (x-1) + -p * (x/(2.0*z)) );
        for(int g = 0; g<left;g++)
        {
            printf(" ");
        }
        printf("#");
        for(int m = left; m<right-1; m++){
            printf(".");
        }
        printf("#");
        printf("\n");
    }
    for(int l=0;l<x;l++){
        printf("#");
    }
    printf("\n");
    return 0;
}

