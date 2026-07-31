#include "trigonometry.h"
#include <math.h>
#define PI 3.14159265


float trigonometry(int a)
{	
	if (a == 1) { return sine(); }
	else if (a == 2) { return cosine(); }
	else if (a == 3) { return tangent(); }
	else return 0;

	
}

float sine()
{
	float h;
	float opp, adj;

	printf("input the opposite: "); scanf("%f", &opp);
	printf("input the adjacent: "); scanf("%f", &adj);

	h = sqrt(power(opp) + power(adj));

	printf("The Hypotenuse is : %f\n", h);
	printf("The sine would be: %f\n", opp / h);

	return opp / h;
}

float cosine()
{
	float h;
	float opp, adj;
	
	printf("input the opposite: "); scanf("%f", &opp);
	printf("input the adjacent: "); scanf("%f", &adj);

	h = sqrt(power(opp) + power(adj));

	printf("The Hypotenuse is : %f\n", h);
	printf("The cosine would be: %f\n", adj / h);

	return adj / h;
}

float tangent()
{
	float h;
	float opp, adj;
	printf("input the opposite: "); scanf("%f", &opp);
	printf("input the adjacent: "); scanf("%f", &adj);

	h = sqrt(power(opp) + power(adj));

	printf("The Hypotenuse is : %f\n", h);
	printf("The tangent would be: %f\n", opp / adj);

	return opp / adj;
}

float power(float x) {
	x = x * x;
	return x;
}

float find_the_angle(float x, int a) {
	if (a == 1) return arc_sin(x);
	else if (a == 2) return arc_cos(x);
	else return arc_tan(x);
}

float arc_sin(float x) {
	return 180 / PI * asin(x);
}

float arc_cos(float x) {
	return 180 / PI * acos(x);
}

float arc_tan(float x) {
	return 180 / PI * atan(x);
}