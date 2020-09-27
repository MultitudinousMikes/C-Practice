#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    char w[256] = { 0 }; 
    int x = 0; 
    int st = getc(stdin);
    while (st != -1)
    {
        if ((st >= 65 && st <= 90) || (st >= 97 && st <= 122) || (st == 39))
        {
            w[i] = (char)st;
	    i++;
            w[i] = 0;
        }
        else
        {
            if (i > 0)
            {
                x = 0;
		j = 1;
                while( j < argc && x == 0)
                {
                    if (strcmp(argv[j], w) == 0)
                    {
                        x = 1;
                        printf("CENSORED");
                    }
		    j++;
                }
                if (x == 0){
		    printf("%s", w);
		}
                w[0] = 0;
                i = 0;
            }
            putc(st, stdout);
        }
        st = getc(stdin);
    } 
    return(0);

}

