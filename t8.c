#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int i=0;
    int arr[3];
    char new;
    while(new!='\n'){
        scanf("%d%c", &arr[i], &new);
        i++;
    }
    int x=arr[0];
    int y=arr[1];
    int n=arr[2];
    int k=0;
    while(k<y)
    {
        if (k==0){
            char a[x+1];
            for(int j = 0; j < x; j++)
            {
                a[j] = '#';
            }
            printf("%s\n", a);
            }
        else if (k==y-1)
        {
            char a[x+1];
            for(int j = 0;j < x; j++)
            {
                a[j] = '#';
            }
            printf("%s\n", a);
        }
        else
        {
            char a[x+1];
            a[0] = '#';
            a[x-1] = a[0];
            for(int j = 1; j<x-1; j++)
            {
                a[j] = '.';
            }
            printf("%s\n", a);
        }
	k++;
    }
}

