#include <stdio.h>
#include <math.h>

int main(){
	float re=0;
	int a=0;
	a = scanf("%f",&re);
	while(a != EOF){
		if(a==0){
		    continue;
		}
		else{
		    printf("%d %d %d\n", (int)floor(re), (int)round(re), (int)ceil(re));
	        a = scanf("%f",&re);
		}
	}
	printf("Done.\n");
	return 0;
}

	

