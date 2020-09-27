#include <stdio.h>
#include <math.h>
int main()
{
    int i = 0;
    float a[10000];
    float x;
    int y;
    y=scanf("%f",&x);
    while(y!=EOF)
    {
        a[i] = x;
        i++;
        y=scanf("%f",&x);
    } 
    int z;
    for(int f=0;f<10000; f++)
    {
      int h = a[f];
      if (h==0)
      {
        z = f;
        break;   
      } 
    }
    float min = a[0];
    float max = a[0];
    float ave = a[0];
    
    for(int k=1 ; k<z;k++)
    {
        if(a[k]<min)
        {
            min = a[k];
        }
        if(a[k]>max)
        {
            max = a[k];
        }    
        ave = ave + a[k];
    }
    ave = ave/(z);
    printf ("%.2f %.2f %.2f\n",min,max,ave);
    return 0;
}
