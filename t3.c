#include <stdio.h>
#include <math.h>

int main()
{
	float n;
	scanf("%f",&n);
	int i = (int)floor(n);
	int y = (int)round(n);
	int k = (int)ceil(n);	
	printf("%d %d %d\n",i,y,k);
	return 0;
}
	
