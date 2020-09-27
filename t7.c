#include <stdio.h>
#include <string.h>
int main(){
    int x;
    int a[100];
    int i=0;
    int p=0;
    while (scanf("%d",&x)!=-1)
    {
        a[i]=x;
	i++;
    }
    while(p<i){
	for(int n=0;n<a[p];n++){
            printf("#");
        }
        printf("\n");
	p++;
    }
    return 0;
}

