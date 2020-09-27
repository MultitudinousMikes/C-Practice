#include <stdio.h>

int main()
{
	char a;
	unsigned char b;
	int c;
	unsigned int i;
	long k;
	unsigned long y;
	float g;
	double h;
	long double j;
	printf("%lu %lu %lu %lu %lu %lu %lu %lu %lu\n", sizeof(a)*8,sizeof(b)*8,sizeof(c)*8,sizeof(i)*8,sizeof(k)*8,sizeof(y)*8,sizeof(g)*8,sizeof(h)*8,sizeof(j)*8);
	return 0;
}
