#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int p;
    int k=0;
    char letter[27]="abcdefghijklmnopqrstuvwxyz";
    char arr[90000];
    char ch;
    ch=getchar();
    float freq;
    while (ch!= EOF)
    {
	    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
	    {
	    	arr[k]=ch;        
	    	k++;
	    }
        ch=getchar();
    }
    float l=k;
    for(int i = 0; i<26;i++)
    {
        p=0;
        for (int j =0; j<k+1;j++)
        {
            if (letter[i]==tolower(arr[j]) || letter[i]==arr[j])
            {
            	p++;
            }
        }
        float q = p;
        freq=q/l;
        if(freq!=0){
            printf("%c %.4f\n", letter[i], freq);
        }
    }
}

