#include "trigonometry.h"
#include "calculus.h"
int main(void)
{
	int choose; printf("CHOOSE BETWEEN 1:SINE 2:COSINE 3:TANGENT: "); scanf("%d", &choose);  
	while (!(choose == 0 || choose == 1 || choose == 2 || choose == 3)) 
	{ 
		printf("wrong input!! Try again: ");
		scanf("%d", &choose); 
	}
	printf("\n");
	float num = trigonometry(choose);

	if (num == 0) {
		return 0;
	}
	else {
		double deg = find_the_angle(num, choose);
		printf("the degree of angle is going to be: %f\n",deg);
		
		float D = differentiation(choose, deg);
		float I = Integral(choose, deg);
		printf("Differentiation value: %f \nIntegral value: %f", D, I);
	}

	return 0;
}