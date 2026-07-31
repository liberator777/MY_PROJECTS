#pragma once
#include "calculus.h"
#include "trigonometry.h"
#define PI 3.14159265

float differentiation(int a, float deg)
{	
	double diff = 0;
	double deltax = 0.0000000001;

	if(a==1) {
		diff = (sin((PI/180)*(deg)+deltax) - sin((PI/180)*(deg))) / deltax;
	}
	else if(a==2) {
		diff = (cos((PI/180)*(deg) + deltax) - cos((PI/180)*(deg))) / deltax;
	}
	else {
		diff = (tan((PI/180)*(deg) + deltax) - tan((PI/180)*(deg))) / deltax;
	}

	return diff;
	
}

float Integral(int a, float deg)
{
	double degtorad = (PI/180)*deg;
	double Inte = 0;
	double sum = 0;
	int t = 10000;
	if (a == 1) {
		for(int i = 0; i <= t; i++) {
			sum = sum + (degtorad /(double) t) * sin(degtorad*double(i/t));
		}
		Inte = sum - cos(0);
		return Inte;
	}
	else if (a == 2) {
		for (int i = 1; i <= t; i++) {
			sum = sum + (degtorad / t) * cos(degtorad*(i/t));
		}
		Inte = sum - sin(0);
		return Inte;
	}
	else {
		for (int i = 1; i <= t; i++) {
			sum = sum + (degtorad / t) * tan(degtorad*(i/t));
		}
		Inte = sum;
		return Inte;
	}
}
