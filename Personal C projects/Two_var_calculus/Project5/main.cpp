#include "Partial_differential.h"
#include "Graph.h"
#pragma warning(disable: 4996)
#pragma warning(suppress: 6385)

int Constant(int v) {
	if (v < 0) {
		return 0;
	}
	else {
		return v+1;
	}
}
int Problem_with_Zero(int v) {
	if (v <= 0) {
		return 0;
	}
	else {
		return v - 1;
	}
}
int main() {
	int total; //number of total monomials
	int x_degree[100] = { 0 }; //degree of x per monomials
	int y_degree[100] = { 0 }; //degree of y per monomials
 	float coe[100] = { 0 }; // coefficient per monomials

	printf("Enter number of monomials: ");  
	scanf("%d", &total);
	printf("\n");
	
	for (int i = total; i > 0; i--) {
		printf("========================================"); printf("\n");
		printf("Enter coefficient of %dth monomial: ",total-i+1); scanf("%f", &coe[i]);
		printf("Enter degree of x in %dth monomial: ",total-i+1); scanf("%d", &x_degree[i]);
		printf("Enter degree of y in %dth monomial: ",total-i+1); scanf("%d", &y_degree[i]); printf("\n");
		printf("========================================");
		printf("\n");
	}

	printf("\n");
	printf("Your original expression is: "); printf("\n");
	for (int i = total; i > 0; i--) {
		if (x_degree[i] == 0 || y_degree[i] == 0) {
			if (y_degree[i] != 0) {
				printf("%.2f*y^%d + ", coe[i], y_degree[i]);
			}
			else if (x_degree[i] != 0) {
				printf("%.2f*x^%d + ", coe[i], x_degree[i]);
			}
			else if (x_degree[i] == 0 && y_degree[i] == 0 && coe[i] == 0) {
				printf("");
			}
			else printf("%.2f + ", coe[i]);
		}
		else if (coe[i] != 0) {
			printf("%.2f*x^%d*y^%d + ", coe[i], x_degree[i], y_degree[i]);
		}
		else
			printf("0");
	}

	printf("0");
	printf("\n");
	printf("-----===========================================-----");
	printf("\n");
	int select; printf("Choose (1)...X OR (2)...Y to differentiate and integralize in : "); scanf("%d", &select);
	printf("\n");
	if (select == 1) {
		printf("DIFFERENTIATION IN TERMS OF X: \n");
		for (int i = total; i > 0; i--) {
			Differentiation(select, coe[i], x_degree[i], y_degree[i]);
		}
		printf("0\n");
		printf("INTEGRAL IN TERMS OF X: \n");
		for (int i = total; i > 0; i--) {
			Integral(select, coe[i], x_degree[i], y_degree[i]);
		}
		printf("C\n");
	}
	else if (select == 2) {
		printf("DIFFERENTIATION IN TERMS OF Y: \n");
		for (int i = total; i > 0; i--) {
			Differentiation(select, coe[i], x_degree[i], y_degree[i]);
		}
		printf("0\n");
		printf("INTEGRAL IN TERMS OF Y: \n");
		for (int i = total; i > 0; i--) {
			Integral(select, coe[i], x_degree[i], y_degree[i]);
		}
		printf("C\n");
	}
	else {
		printf("Quit");
		return 0;
		}
	printf("\n-----------ORIGNINAL----------|------------DIFFER----------|--------------INTE------------\n");
	float sum[100][100] = { { 0 } };
	float sum_D[100][100] = {{0}};
	float sum_I[100][100] = { {0} };
	float z, z_D, z_I;
	float z_coor[100][100] = { {0} };
	float z_coor_D[100][100];
	float z_coor_I[100][100];
	for (int i = 0; i <= 25;i++) {
		for (int j = 0; j <= 25; j++) {
			for (int k = total; k > 0; k--) {
				if (select == 1) {
					z = z_coordination(i, j, coe[k], x_degree[k], y_degree[k]);
					z_D = z_coordination(i, j,coe[k] * x_degree[k],Problem_with_Zero( x_degree[k]), y_degree[k]);
					z_I = z_coordination(i, j, coe[k] /( x_degree[k] + 1), Constant(x_degree[k]), y_degree[k]);
				}
				else {
					z = z_coordination(i, j, coe[k], x_degree[k], y_degree[k]);
					z_D = z_coordination(i, j, coe[k] * y_degree[k], x_degree[k], Problem_with_Zero(y_degree[k]));
					z_I = z_coordination(i, j, coe[k] /( y_degree[k] + 1), x_degree[k], Constant(y_degree[k]));
				}
				 sum[i][j] += z;
				 sum_D[i][j] += z_D;
				 sum_I[i][j] += z_I;
			}
			z_coor[i][j] = sum[i][j];
			z_coor_D[i][j] = sum_D[i][j];
			z_coor_I[i][j] = sum_I[i][j];

		printf("( X = %d. Y = %d, Z = %.2f ) ", i, j, z_coor[i][j]);
		printf(" ( X = %d. Y = %d, Z = %.2f ) ", i, j, z_coor_D[i][j]);
		printf(" ( X = %d. Y = %d, Z = %.2f ) \n", i, j, z_coor_I[i][j]);

		}
	}

FILE* temp0 = fopen("coordinates.temp", "w"); 
FILE* temp1 = fopen("coordinates_D.temp", "w");
FILE* temp2 = fopen("coordinates_I.temp", "w");

fprintf(temp0, "set title 'graph of two-variable_equation'\n");
for (int i = 0; i <=25; i++) {
	for (int j = 0; j <= 25; j++) {
		fprintf(temp0, "%d %d %.2f\n", i, j, z_coor[i][j]);
	}
	printf("\n");
}
fclose(temp0);

fprintf(temp1, "set title 'differential'\n");
for (int i = 0; i <= 25; i++) {
	for (int j = 0; j <= 25; j++) {
		fprintf(temp1, "%d %d %.2f\n", i, j, z_coor_D[i][j]);
	}
	printf("\n");
}
fclose(temp1);

fprintf(temp2, "set title 'integraled'\n");
for (int i = 0; i <= 25; i++) {
	for (int j = 0; j <= 25; j++) {
		fprintf(temp2, "%d %d %.2f\n", i, j, z_coor_I[i][j]);
	}
	printf("\n");
}
fclose(temp2);

FILE* GP = _popen("gnuplot -p", "w");
fprintf(GP, "%s \n", "set title 'coordinates on 3D-graph'");
fprintf(GP, "%s \n", "set xlabel 'X'");
fprintf(GP, "%s \n", "set ylabel 'Y'");
fprintf(GP, "%s \n", "set zlabel 'Z'");
fprintf(GP, "%s \n", "set palette rgb 33, 13, 10");
fprintf(GP, "%s \n", "splot 'coordinates.temp' using 1:2:3 w lp pt 7 ps 1 lc rgb 'green'");
fprintf(GP, "%s \n", "pause 5");
fprintf(GP, "%s \n", "splot 'coordinates_D.temp' using 1:2:3 w lp pt 7 ps 1 lc rgb 'red'");
fprintf(GP, "%s \n", "pause 5");
fprintf(GP, "%s \n", "splot 'coordinates_I.temp' using 1:2:3 w lp pt 7 ps 1 lc rgb 'blue'");
fprintf(GP, "%s \n", "pause 5");
fflush(GP);

getchar();

_pclose(GP);

 return 0;
}