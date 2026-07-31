#include "Partial_differential.h"

int Differentiation(int s, float c, int x, int y) {
	if (s == 1) {
		if (x == 1) {
			if (y >= 1) {
				printf("%.2f*y^%d + ", c, y);
			}
			else {
				if (c == 0) { printf(""); }
				else { printf("%.2f", c); }
			}
		}
		else if (x == 0) {
			printf("");
		}
		else {
			printf("%.2f*x^%d*y^%d +", c * x, x - 1, y);
		}
	}
	else {
		if (y == 1) {
			if (x >= 1) {
				printf("%.2f*x^%d + ", c, x);
			}
			else {
				if (c == 0) { printf(""); }
				else { printf("%.2f", c); }
			}
		}
		else if (y == 0) {
			printf("");
		}
		else {
			printf("%.2f*x^%d*y^%d +", c * y, x, y-1);
		}
	}
	return 0;
}
int Integral(int s, float c, int x, int y) {
	if (s == 1) {
		if (y == 0) {
			if (c == 0) {
				printf("C + ");
			}
			else {
				printf("%.2f*x^%d + ",c/(x+1),x+1);
			}
		}
		else {
			printf("%.2f*x^%d*y^%d + ", c / (x + 1), x + 1, y);
		}
	}
	else {
		if (x == 0) {
			if (c == 0) {
				printf("C + ");
			}
			else {
				printf("%.2f*y^%d + ", c / (y + 1), y + 1);
			}
		}
		else {
			printf("%.2f*x^%d*y^%d + ", c / (y + 1), x, y + 1);
		}
	}
	return 0;
}