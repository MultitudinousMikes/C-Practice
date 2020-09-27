#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int flag;
    if (argc==3){
        char *str1=argv[1];
    	char *str2=argv[2];
    	int count1 = 0, count2 = 0;
    	while (str1[count1] != '\0'){
            count1++;
    	}
    	while (str2[count2] != '\0'){
            count2++;
    	}
    	for (int i = 0; i <= count1 - count2; i++)
    	{
            for (int j = i; j < i + count2; j++)
            {
            	flag = 1;
            	if (str1[j] != str2[j - i])
            	{
                    flag = 0;
                    break;
            	}
            }
            if (flag == 1){
            	break;
            }
    	}
    }
    if (flag == 1){
        printf("true\n");
    }
    else{
        printf("false\n");
    }
}
