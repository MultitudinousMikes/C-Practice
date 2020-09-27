#include <stdio.h>
#include <math.h>

int main()
{
	float n;
	float b = 3.1415;
	b = scanf("%f",&n);	
	int i = (int)floor(n);
	int y = (int)round(n);
	int k = (int)ceil(n);
	int d = 0;
	if (b==1)
	{
		printf("%d %d %d\n",i,y,k);
	}
	else
	{
		printf("scanf error: (%d)\n",d);
	}
	return 0;
}

